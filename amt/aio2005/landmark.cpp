#include <cstdio>
#include <utility>

FILE* input;
FILE* output;

using namespace std;
int r, c;

char a[1005][1005];

pair<int, int> start;
pair<int, int> end;
pair<int, int> max_start;
pair<int, int> max_end;

int max(int a, int b) { return a>b?a:b; }

int main() 
{
    input = fopen("landin.txt", "r");
    output = fopen("landout.txt", "w");

    fscanf(input, "%d%d", &r, &c);

    for(int i = 0; i < r; i++) {
        fscanf(input, "%s", &a[i]);
    }

    int curr_max = 0;
    int curr = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a[i][j]=='.')
                curr+=1;
            else
                curr = 0;
            if(curr>curr_max) {
                max_end = {i+1, j+1};
                max_start = {i+1, j-curr+2};
                curr_max = curr;
            }
                
        }
        curr=0;
    }

    curr = 0;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            if(a[j][i]=='.')
                curr+=1;
            else
                curr=0;
            if(curr>curr_max) {
                max_end = {j+1, i+1};
                max_start = {j-curr+2,i+1};
                curr_max = curr;
            }
        }
        curr=0;
    }

    fprintf(output, "%d %d %d %d", max_start.first, max_start.second, max_end.first, max_end.second);

    fclose(input);
    fclose(output);

    return 0;

}
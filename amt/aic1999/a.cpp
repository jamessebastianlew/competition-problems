#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

FILE* input;
FILE* output;

int temp;
int n;
int cnt;

unordered_map<int, int> dp;

int main() {
    
    input = fopen("hailin.txt", "r");
    output = fopen("hailout.txt", "w");

    

    while( fscanf(input, "%d", &n) ) {
        cnt = 0;
        temp = n;
        while (temp != 1) {
            if(dp.find(temp)!=dp.end()) {
                cnt+=dp[temp];
                break;
            }
            if(!(temp&1))
                temp >>= 1;
            else
                temp=3*temp+1;
            cnt++;
        }
        dp[n]=cnt;
        fscanf(input, "%d", &n);
    }

    fclose(input);
    fclose(output);

    return 0;

}
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
//basic bfs REMEMBER TO CHECK FOR ODD AND EVEN VALUES OF K 
//(can add boolean to visited and don't need to add boolean to queue)

using namespace std;

FILE* input;
FILE* output;

const int MAX_N = 100005, MAX_E = 100005;
int n, e, x, k;

int curr_node; // node
int curr_k; //hops

int curr_unique = 0;

queue<pair<int, int>> qq;

bool visited[MAX_N][2];
bool can_reach[MAX_N];

vector<int> adj_m[MAX_N];

int main() {
    input = fopen("evadingin.txt", "r");
    output = fopen("evadingout.txt", "w");

    fscanf(input, "%d%d%d%d", &n, &e, &x, &k);
    int tempU, tempV;

    for(int i = 0; i < e; i++) {
        fscanf(input, "%d%d", &tempU, &tempV);
        adj_m[tempU].push_back(tempV);
        adj_m[tempV].push_back(tempU);
    }

    qq.push({x, k});

    while(!qq.empty()) {
        curr_node = qq.front().first;
        curr_k = qq.front().second;
        qq.pop();

        visited[curr_node][curr_k&1]=true;
        
        if(!( curr_k&1 || can_reach[curr_node] )) {
            curr_unique++;
            can_reach[curr_node]=true;
        }

        if(curr_k == 0)
            continue;
            
        for(int node : adj_m[curr_node] ) {
            if(visited[node][(curr_k-1)&1])
                continue;
            visited[node][(curr_k-1)&1]=true;
            qq.push({node, curr_k-1});
        }
    }

    fprintf(output, "%d", curr_unique);

    fclose(input);
    fclose(output);

    return 0;
}

#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

const int MAX_N = 50000;

using namespace std;

int n;

int sculp[MAX_N*2];

// real index, my index
int child[MAX_N+1][2];
int parent_ind[MAX_N+1];
int curr_max;
int total_cost = 0;

int dfs(int curr_i) {
    if(child[curr_i][0]==0)
        return curr_max-sculp[curr_i];
    total_cost+=abs(sculp[child[curr_i][0]]-sculp[child[curr_i][1]]) 
    return min(dfs(child[curr_i][0]),dfs(child[curr_i][1]));
}



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("dancein.txt","r",stdin);
    freopen("danceout.txt","w",stdout);
#endif

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> x >> b >> y;

        child[i][0]=a;
        child[i][1]=b;

        parent_ind[a]=i;
        parent_ind[b]=i;

        sculp[child[i][0]]=sculp[i]+x;
        sculp[child[i][1]]=sculp[i]+y;
        
        curr_max = max(sculp[a], sculp[b]);        
    }
   
    int temp = dfs(1);

    return 0;

}

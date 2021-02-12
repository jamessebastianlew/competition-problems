#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }

using namespace std;

const int mxN = 2e5+5;
int n;
int u, v;

vector<int> adj[mxN];
bool col[mxN];

int dp[mxN];

bool vis[mxN];
int dfs1(int curr) {
    vis[curr] = true;
    int temp = col[curr]*2-1;
    for(int node : adj[curr])
        if(!vis[node]) amax(temp, temp+dfs1(node));
    return dp[curr] = temp;
}

bool seen[mxN];
int ans[mxN];

void dfs2(int curr, int from) {
    seen[curr] = true;
    dp[curr] = max(dp[curr], dp[curr]+dp[from]);

    for(int node : adj[curr]) {
        if(seen[node]) continue;
        int temp = max(0, dp[node]);
        dp[curr]-=temp;
        dfs2(node, curr);
        dp[curr]+=temp;
    }
}

    
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> col[i];
    for(int i=0; i<n-1; ++i)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    
    dfs1(1);
    dfs2(1, 0);

    for(int i=1; i<=n; ++i)
        cout << dp[i] << ' ';
    cout << endl;


    return 0;

}


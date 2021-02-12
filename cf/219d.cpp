#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
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

using namespace std;

int n;
const int mxN = 2e5+1;

vector<int> adj[mxN];
vector<int> adj_t[mxN];

bool vis1[mxN];
int dfs1(int u) {
    vis1[u] = true;
    int sm = 0;
    for(int v : adj[u])
        if(!vis1[v]) sm+=dfs1(v);
    for(int v : adj_t[u])
        if(!vis1[v]) sm+=dfs1(v)+1;
    return sm;
}

int ans = 0x3f3f3f3f;
bool vis2[mxN];

int best[mxN];

void dfs2(int u, int sm) {
    vis2[u] = true;

    best[u] = sm;
    amin(ans, sm);

    for(int v : adj[u])
        if(!vis2[v]) dfs2(v, sm+1);
    for(int v : adj_t[u])
        if(!vis2[v]) dfs2(v, sm-1);
}
    

    
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    int u, v;
    for(int i=0; i<n-1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    }

    //select arbitrary starting node

    ans = dfs1(1);
    dfs2(1, ans);


    cout << ans << endl;
    for(int i=1; i<=n; ++i)
        if(best[i] == ans)
            cout << i << ' ';
    cout << endl;

    return 0;

}


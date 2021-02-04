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
const int mxV = 3001;
int n;

int dists[mxV];
bool vis[mxV];

void solve() {
    int V, E, start;
    int u, v, x;

    memset(dists, 0x3f, sizeof(dists));
    memset(vis, 0, sizeof(vis));

    cin >> V >> E;

    vector<array<int, 2>> adj_m[mxV];
    for(int i=0; i<=V; ++i)
        adj_m[i].reserve(3000);
    for(int i=0; i<E; ++i) {
        cin >> u >> v >> x;
        adj_m[u].push_back({v, x});
        adj_m[v].push_back({u, x});
    }
    cin >> start;

    dists[start] = 0;

    priority_queue<array<int, 2>, vector<array<int,2>>, greater<array<int,2>>> qq;
    qq.push({0,start});

    while(!qq.empty()) {
        array<int, 2> curr = qq.top();
        qq.pop();

        int u = curr[1];
        if(vis[u])
            continue;

        vis[curr[1]] = true;

        for(array<int, 2> edge : adj_m[curr[1]]) {
            if(dists[curr[1]] + edge[1] < dists[edge[0]]) 
                dists[edge[0]] = dists[curr[1]]+edge[1], qq.push({dists[edge[0]], edge[0]});
        }
    }
    for(int i=1; i<=V; ++i)
        if(i!=start)
            cout << (dists[i]==0x3f3f3f3f?-1:dists[i]) << ' ';
    cout << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;

}


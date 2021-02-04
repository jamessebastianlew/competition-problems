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

const int mxV = 100001;
const int mxE = 100001;
const int mxK = 10000;
int V, E, K;

int special_node[mxK];
vector<array<int, 2>> adj[mxV];
vector<int> inorder, st;

int indegree[mxV];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> V >> E >> K;

    inorder.reserve(V+1);

    for(int i=0; i<K; ++i) cin >> special_node[i];

    int u, v, x;
    for(int i=0; i<E; ++i)
        cin >> u >> v >> x, adj[u].push_back({v, x}), ++indegree[v];

    for (int i = 1; i <= V: i++) if (indegree[i]==0) st.push_back(i);

    while (!st.empty()) {
        int u = st.back(); st.pop();
        inorder.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) st.push_back(v);
    }



    return 0;
}

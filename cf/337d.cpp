
#include <bits/stdc++.h>

typedef long long ll;

#define cio() ios::sync_with_stdio(0); cin.tie(0);
#ifndef FLOSH
    #define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
    #define fio(in, out) cio()
#endif
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxn = 1e5+1;
int a,b,x;
int n,m,d;
int dist[mxn];
bool marked[mxn];
vector<int> adj[mxn];

int init_dfs(int u, int par) {
    if(marked[u]) dist[u] = 0;

}

int main() {
    cio();
    cin >> n >> m >> d;

    for(int i=0; i<m; ++i)
        cin >> x, marked[x] = true;

    for(int i=1; i<n; ++i) {
        cin >> a >> b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    init_dfs(1, 1);

    return 0;
}

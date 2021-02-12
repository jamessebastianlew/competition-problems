#include <bits/stdc++.h>

typedef long long ll;

#ifndef FLOSH
#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
#define fio(in, out)
#endif
#define cio() ios::sync_with_stdio(0); cin.tie(0);
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
vector<array<int,2>> adj[mxn];
int num_nodes[mxn];
int total = 0;
int n, m;

int is_lucky(int x) {
    for(; x > 0; x /= 10) if((x%10) != 4 && (x%10)!=7) return false;
    return true;
}


int line_count = 0;
// returning the number of nodes in the subtree
// that were visited via at least one lucky edge
int dfs(int u, int par) {
    int cnt = 0;
    for(const auto& [v, x] : adj[u]) {
        if(v == par) continue;
        if(x) cnt += num_nodes[v], line_count += num_nodes[v];
        else cnt += dfs(v, u);
    }
    

    return cnt;
}

// counting children 
int subtree_count(int u, int par) {
    int cnt = 1;
    for(const auto& [v, x] : adj[u])
        if(v != par) cnt += subtree_count(v, u);
    return num_nodes[u] = cnt;
}

int main() {
    cio();
    cin >> n;
    m = n -1;
    int a, b, x;
    while(m--) {
        cin >> a >> b >> x;
        --a, --b;
        adj[a].push_back({b, is_lucky(x)});
        adj[b].push_back({a, is_lucky(x)});
    }
    subtree_count(0, 0);

    cout << dfs(0, 0) * 6 << endl;

    return 0;
}

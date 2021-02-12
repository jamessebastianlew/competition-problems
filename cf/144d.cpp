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
int n, m, s, l;
int shortest[mxn];
bool vis[mxn];
vector<array<int,2>> adj[mxn];
int len;
array<int,3> edges[mxn];

function<bool(array<int,2>, array<int,2>)> comp = [](auto a, auto b) {return a[1] > b[1];};

int main() {
    cin >> n >> m >> s;
    --s;

    for(int i=0; i<m; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        --a, --b;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});

        edges[len++] = {a, b, x};
    }
    cin >> l;

    priority_queue<array<int, 2>, vector<array<int, 2>>, function<bool(array<int,2>, array<int,2>)>> qq(comp);
    qq.push({s,0});
    while(!qq.empty()) {
        auto [a, dist] = qq.top(); qq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        shortest[a] = dist;
        for(auto [b, x] : adj[a]) {
            if(!vis[b]) {
                qq.push({b, dist + x});
            }
        }
    }

    int cnt = 0;

    // go through each city and add the ones l dist
    for(int i=0; i<n; ++i) if(shortest[i] == l) ++cnt;
    //for(int i=0; i<n; ++i) cout << shortest[i] << ' ' ; cout << endl;


    // go through each edge and if you can make it to a point 
    // exactly l add it
    for(int i=0; i<m; ++i) {
        auto [a, b, x] = edges[i];
        // consider a as the starting point 
        int z = l - shortest[a];
        int z2 = l - shortest[b];
        if(z > 0 && z < x && shortest[a] + z < (x-z) + shortest[b]) ++cnt;
        if(z2 > 0 && z2 < x && shortest[b] + z2 <= (x-z2) + shortest[a]) ++cnt;
    }
    cout << cnt << endl;
    
    return 0;
}

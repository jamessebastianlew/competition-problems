#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxN =1e6+5;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int k;
int h, w;
int p[4];
array<int,3> ans;

int main() {
    cio();

    cin >> h >> w >> k;
    for(int i=0; i<4; ++i) cin >> p[i], --p[i];

    vector<string> gd(h);
    for(int i=0; i<h; ++i) cin >> gd[i];

    vector<vector<bool>> vis(h, vector<bool>(w));
    vector<vector<array<int,2>>> dp(h, vector<array<int,2>>(w, {-1, 0}));

    queue<array<int, 2>> qq;
    while(!qq.empty()) {
        auto u = qq.front(); qq.pop();
        if(vis[u[0]][u[1]]) continue;
        vis[u[0]][u[1]] = true;

        for(int i=0; i<4; ++i) {
            int nr = u[0]+dr[i], nc = u[1]+dc[i];
            if(ins(nr, nc))

        
    }

    return 0;
}

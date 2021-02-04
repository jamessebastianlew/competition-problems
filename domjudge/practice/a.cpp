
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

const int mxn = 3;
array<ll, 2> sz[mxn];
array<ll, 2> curr[mxn];

ll solve() {
    //pick the top left
    array<ll, 2> total = {0,0};
    ll mn = 0x3f3f3f3f3f3f3f3f;
    for(int i=0; i<3; ++i) for(int j=0; j<3; ++j) for(int k=0; k<3; ++k) {
        if(i==j || j==k || i==k) continue;
        total = {curr[i][0], curr[i][1]};
        // pick right
        total[0] = {total[0] + curr[j][0]};
        total[1] = max(total[1], curr[j][1]);

        if(curr[k][0] <= curr[i][0])
            total[1] = max(curr[k][1] + curr[i][1], total[1]);
        else
            total[1] += curr[k][1]
        amin(mn, (ll)total[0] * (ll)total[1]);

    }
    return mn;
}
int main() {
    cio();
    for(int i=0; i<3; ++i) for(int j=0; j<2; ++j) cin >> sz[i][j];

    ll mn = 0x3f3f3f3f3f3f3f3f;
    for(int i=0; i<2; ++i) for(int j=0; j<2; ++j) for(int k=0; k<2; ++k) {
        array<int, 3> temp = {i, j, k};
        for(int p=0; p<3; ++p)
            curr[p][0] = sz[p][temp[p]], curr[p][1] = sz[p][(temp[p]+1)<2?temp[p]+1:temp[p]];
        amin(mn, solve());
    }
    cout << mn << endl;

        
        

    return 0;
}

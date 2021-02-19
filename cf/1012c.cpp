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

const int mxn = 5e3+1;
int dp[mxn][mxn]; // dp[l][r]
const int mxm = 5e2+2;
int bdp[mxm][mxm][mxm]; // stands for bad dp

// for k=1 it is easy
// for k=2 the only reason you would choose different to k=1
// + making the next cheapest hill would be if you were on a different
// parity?

int n;
int aa[mxn];

int C(int i, int l, int r) {
    int cost = 0;
    if(i-1 >= 0) {
        int left = aa[i-1];
        if(l == i-1 && i-2 >= 0) left = min(aa[i-1], aa[i-2]-1);
        if(left >= aa[i]) cost += left - (aa[i]-1);
    }
    if(i+1 < n) {
        int right = aa[i+1];
        if(r == i+1 && i+2 < n) right = min(right, aa[i+2]-1);
        if(right >= aa[i]) cost += right - (aa[i]-1);
    }
    return cost;
}

int cc[mxn];

int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    /*
    simple O(n^5) algorithm
    dp[mxn][mxn][mxn];

    // find the best of height k
    for(int k=1; k<=(n+1)/2; ++k) {
        // consider exclusive bound (l, r)
        for(int l=n; l>=-1; --l) for(int r=l+2; r<=n; ++r) {
            // choose an hill to be a house
            for(int i=l+1; i<r; ++i) {
                minimise(dp[l][r][k], cost to make a house at i and k-1 other houses);
            }
        }
    }
    // noting the cost to make a house at i and k-1 other houses is
    // min from z=0 to k-1 of (C(i) + dp[l][i-1][z] + dp[i+1][r][k-1-z])
    */


    // implementing O(n^5)
    memset(bdp, 0x3f, sizeof(bdp));
    for(int k=0; k<=(n+1)>>1; ++k) for(int l=n+1; l>=0; --l)
    for(int r=l; r<=n+1; ++r) {
        if(k==0) bdp[l][r][k] = 0;
        else for(int i=l+1; i<r; ++i) for(int z=0; z<=k-1; ++z)
            amin(bdp[l][r][k], C(i-1, l-1, r-1) + bdp[l][i-1][z] + bdp[i+1][r][k-1-z]);
    }
    for(int k=1; k<=(n+1)>>1; ++k) cout << bdp[0][n+1][k] << ' ';
    cout << endl;

    return 0;
}

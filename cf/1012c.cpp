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
// for k=1 it is easy
// for k=2 the only reason you would choose different to k=1
// + making the next cheapest hill would be if you were on a different
// parity?

int n;
int aa[mxn];
int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    /*
    simple O(n^5) algorithm
    dp[mxn][mxn][mxn];

    // find the best of height k
    for(int k=1; k<=(K+1)/2; ++k) {
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


    return 0;
}

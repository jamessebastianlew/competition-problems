#include <bits/stdc++.h>

using namespace std;

int n, m;

const int mxn = 5001;
int a[mxn];
int dp[mxn];
int len = 0;

int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    double temp;
    for(int i=0; i<n; ++i) cin >> a[i] >> temp;
    memset(dp, 0x3f, sizeof(dp));

    for(int i=0; i<n; ++i) {
        if(len == 0 || a[i] >= dp[len-1]) { dp[len++] = a[i]; continue; }
        int lo = -1, hi = len;
        while(lo+1<hi) {
            int mid = (lo+hi)>>1;
            if(a[i] < dp[mid]) hi = mid;
            else lo = mid;
        }
        dp[hi] = a[i];
    }
    cout << (n - len) << endl;
    return 0;
}

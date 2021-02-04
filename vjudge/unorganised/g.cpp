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

const int mxn = 1e2+1;
int n;
int aa[mxn];
int dp[mxn][3]; // 0 contest 1 sport 2 rest

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> aa[i];
    for(int i=0; i<3; ++i)
        dp[0][i] = 0;

    for(int i=1; i<=n; ++i) {
        int rest = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + 1;
        int sport = min(dp[i-1][0], dp[i-1][2]);
        int contest = min(dp[i-1][1], dp[i-1][2]);

        if(aa[i]==3 || aa[i]==1) amin(dp[i][0], contest);
        if(aa[i]==3 || aa[i]==2) amin(dp[i][1], sport);
        amin(dp[i][2], rest);
    }

    int ans = 0x3f3f3f3f;
        
    if(aa[n]==3 || aa[n]==1) amin(ans, dp[n][0]);
    if(aa[n]==3 || aa[n]==2) amin(ans, dp[n][1]);
    amin(ans, dp[n][2]);

    cout << ans;

    return 0;
}

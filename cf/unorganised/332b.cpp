
#include <bits/stdc++.h>

typedef long long ll;

#define debug(something) something
#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long

int n, k;

const int mxN = 2e5+5;
int pref_sums[mxN];
array<int, 3> dp[mxN]; // value, index, last index

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i )
        cin >> pref_sums[i], pref_sums[i] += pref_sums[i-1];

    array<int, 3> ans = {0,0,0};
    for(int i = n-k+1; i > 0; --i ) {
        dp[i][0] = dp[i+k][0] + pref_sums[i+k-1] - pref_sums[i-1];
        dp[i][1] = i;
        dp[i][2] = dp[i+k][1];

        if(dp[i+1][0] > dp[i][0])
            dp[i] = dp[i+1];
        if(dp[i][0] >= ans[0])
            ans = dp[i];
    }

    cout << ans[1] << ' ' << ans[2] << endl;

    return 0;

}


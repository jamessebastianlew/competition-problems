
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

int n, m;

const int mxN = 6;
const int mxM = 50001;

int a[mxM][mxN];
int dp[mxM][mxN];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for(int i = 1; i<= m; ++i) for(int j = 1; j <= n; ++j)
        cin >> a[i][j];

    for(int i = 1; i<=n; ++i) for(int j = 1; j<=m; ++j)
            dp[j][i]=max(dp[j][i-1], dp[j-1][i]) + a[j][i];
    for(int i = 1; i<=m; ++i)
        cout << dp[i][n] << ' ';
    cout << endl;

    return 0;

}


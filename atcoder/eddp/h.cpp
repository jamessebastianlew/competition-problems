
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int h, w;

char grid[1001][1001];
int dp[1001][1001];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    for(int i=0;i<h;++i) for(int j=0; j<w; ++j) cin >> grid[i][j];
    dp[0][0]=1;

    for(int i=0;i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(grid[i][j]=='.')
                dp[i][j+1]+=dp[i][j]%MOD, dp[i+1][j]+=dp[i][j]%MOD;
        }
    }

    cout << dp[h-1][w-1]%MOD << endl;


    return 0;

}


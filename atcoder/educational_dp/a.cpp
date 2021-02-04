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
int k;

int dp[100005];
int heights[100005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;

    poiu(n) cin >> heights[i];

    for(int i=0; i<n; ++i) {
        for( int j=i+1; j<=i+k && j<n; j++) {
            min_self(dp[j], dp[i]+abs(heights[i]-heights[j]));
        }
    }

    cout << dp[n-1] << endl;
    return 0;

}


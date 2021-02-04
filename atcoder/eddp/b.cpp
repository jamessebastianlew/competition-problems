
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD (int)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxN = 1e5+5;

int n;
int h, temp;

int dp[mxN];
int stones[mxN];
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, 0x3f, sizeof(int)*mxN);
    
    int k;
    cin >> n >> k;

    for(int i = 0; i<n;i++) cin >> stones[i];
    
    dp[0]=0;

    for(int i=0; i<n; i++) {
        for(int x=i+1; x<=i+k&&x<n; x++) {
            min_self(dp[x], dp[i]+abs(stones[i]-stones[x]));
        }
    }
    cout << dp[n-1] << endl;
    


    return 0;

}


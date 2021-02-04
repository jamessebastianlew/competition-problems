
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

int n,m;
string s;
string t;
const int mxN = 3001;

int dp[mxN][mxN];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> s >> t;
    
    n = s.size();
    m = t.size();

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=max({dp[i][j-1],dp[i-1][j-1]+(s[i-1]==t[j-1]),dp[i-1][j]});
        }
    }
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << dp[n][m] << endl;

    int i =n,j=m;
    while(i!=0&&j!=0) {
        if(dp[i][j-1]!=dp[i][j])
            cout << j << ' ', i--,j--;
        else
            j--;
    }




    return 0;

}


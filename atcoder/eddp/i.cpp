
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

int n;
double temp;

double dp[3000];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0]=1;

    for(int coin=0; coin<n; ++coin) {
        cin >> temp;
        
        for(int i=coin+1; i>=0; --i) {
            dp[i]=(i==0? 0 : dp[i-1]*temp) + dp[i]*(1-temp);
        }
    }

    double ans = 0;
    for(int i=0; i<=n; ++i) {
        int tails = n-i;
        if(i>tails)
            ans+=dp[i];
    }
    printf("%.10lf\n", ans);
    return 0;

}


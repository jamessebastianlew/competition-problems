#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c, d, e, f;
const int mxN = 10005;
bool seen[mxN];
int dp[mxN];
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
}
#undef int
int main() {
#define int long long
    int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        memset(dp,-1,sizeof(dp));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

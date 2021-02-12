
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
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }

using namespace std;

int n, k, t;
int a,b;

const int mxN = 1e5+5;
int dp[mxN]; // dp[i] is num_ways to make sequence ending at i

//at each step you can either take a red flower, or try taking white group, if you 
//take a white group then you add the number of combinations k before to dp[i],
//if you take a red group you can add the number of combinations one before to dp[i]

//the number of ways to eat between a and b flowers is the number of ways to eat b
//flowers minus the number of ways to eat a-1 flowers


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[0] = 1;
    cin >> t >> k;

    for(int i=0; i<=100000; ++i) {
        if(i+k<=100000)
            sadd(dp[i+k], dp[i]);
        if(i+1<=100000)
            sadd(dp[i+1], dp[i]);
        if(i>0)
            sadd(dp[i], dp[i-1]);
    }

    int ans;
    for(int i=0; i<t; ++i) {
        cin >> a >> b;
        ans = dp[b] - dp[a-1];
        if(ans < 0) ans+=MOD;
        cout << ans << endl;
    }

    return 0;

}


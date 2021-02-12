#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
#define MOD 100000000
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }

using namespace std;

const int mxN = 101;
const int mxK = 10;
int n1, n2, k1, k2;

int dp[mxN][mxN][2]; 

// dp[i][0] number of ways with a soldier
// dp[i][1] number of ways with a horse guy

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n1 >> n2 >> k1 >> k2;

    dp[0][0][1] = dp[0][0][0] = 1;

    for(int i=0; i<=n1; ++i) {
        for(int j=0; j<=n2; ++j) {
            for(int l=min(i,k1); l>0; --l) sadd(dp[i][j][0], dp[i-l][j][1]);
            for(int l=min(j,k2); l>0; --l) sadd(dp[i][j][1], dp[i][j-l][0]);
        }
    }

    cout << (dp[n1][n2][1]+dp[n1][n2][0])%MOD << endl;



    return 0;

}


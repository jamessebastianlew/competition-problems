#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
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

int n;

const int mxN = 100001;
int a[mxN];
int dp[1000001];
int total = 0;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[0] = 1;

    int curr;
    vector<int> lo_factors, hi_factors;
    lo_factors.reserve(2000);
    hi_factors.reserve(2000);
    while(n--) {
        lo_factors.clear();
        hi_factors.clear();
        cin >> curr;
        for(int lo=1; lo*lo<=curr; ++lo) {
            if(curr%lo==0) {
                int hi = curr/lo;
                lo_factors.push_back(lo);
                if(hi!=lo)
                    hi_factors.push_back(hi);
            }
        }
        for(int t : hi_factors)
            sadd(dp[t], dp[t-1]);
        for(int i=poius(lo_factors)-1; i>-1; --i)
            sadd(dp[lo_factors[i]], dp[lo_factors[i]-1]);
    }

    for(int i=1; i<1000001; ++i)
        sadd(total, dp[i]);
    cout << total << endl;

    return 0;

}


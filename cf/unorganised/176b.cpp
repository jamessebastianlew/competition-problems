#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MODT 100000000700000000LL
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }


using namespace std;

const int mxK = 1e5+5;
const int mxN = 1e3+5;
int n, K;

string s, t;
int dp1[mxN];
int dp2[mxN];
int* temp_swap = dp2;
bool pref_suf[mxN];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t >> K;

    n=poius(s);
    string temp_one, temp_two;

    // you can achieve a split at i by the number of ways
    // you can achieve other splits except for i
    long long curr_pref;
    dp1[0] = 1;
    while(K--) {
        curr_pref = 0;
        for(int i=0; i<n; ++i) curr_pref+=dp1[i];
        for(int i=0; i<n; ++i) dp2[i] = (int)((curr_pref-dp1[i])%MOD);
        swap(dp1, dp2);
    }
            
    //test all the combinations with that split that
    //lead to $t$
    string conc;
    int total = 0;
    for(int i=0; i<n; ++i) {
        temp_one.assign(s, 0, i);
        temp_two.assign(s, i, n-i);
        conc = temp_two + temp_one;
        if(conc == t) sadd(total, dp1[i]);
    }
    
    cout << total << endl;

    return 0;

}


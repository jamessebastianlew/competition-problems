
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


using namespace std;
#define int long long

const int INF = 1000000000000000LL;

int n;
int a[100001];
int dp[100001][2];

string reversed(string s) {
    int n = poius(s);
    char temp;
    for(int i = 0; i < n>>1; ++i)
        temp = s[i], s[i] = s[n-i-1], s[n-i-1] = temp;
    return s;
}
        

#undef int
int main() {
#define int long long    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    memset(dp, 0x0f, sizeof(dp));
    for(int i=1; i<=n; ++i) cin >> a[i];

    string curr, prv="";
    string testing_curr, testing_prev;

    dp[0][0] = dp[0][1] = 0;
    for(int i=1; i<=n; ++i) {
        cin >> curr;
        for(int j=0; j<2; ++j) for(int l=0; l<2; ++l) {
            testing_curr = j?reversed(curr):curr;
            testing_prev = l?reversed(prv):prv;
            if(testing_curr>=testing_prev)
                amin(dp[i][j], dp[i-1][l] + (j?a[i]:0));
            else
                amin(dp[i][j], INF);
        }
        prv = curr;
    }
    
    int ans = min(dp[n][1], dp[n][0]);
    cout << (ans<INF?ans:-1) << endl;

    return 0;

}


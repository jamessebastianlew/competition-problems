
#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
int amod(T a, T m) { return (a%m + m)%m; }

using namespace std;

const int mxn = 101, mxm = 101, mxk = 11;
int n, m, K;
char temp;

int aa[mxn][mxm];
int dp[mxn][mxm][mxk];
int from[mxn][mxm][mxk];
// dp[i][j][k] max at pos [i][j] with module [k]
// dp[i][j][k] = for 0<=k<K max(dp[i-1][j-dc][( k-val(i,j) )%K])+val[i][j]

int main() {
    cio();
    cin >> n >> m >> K;
    ++K;
    for(int i=n-1; i>=0; --i) for(int j=0; j<m; ++j)
        cin >> temp, aa[i][j] = temp - '0';
    
    memset(dp, 0xc3, sizeof(dp));

    for(int j=0; j<m; ++j)
        dp[0][j][amod(aa[0][j], K)] = aa[0][j];
    
    for(int i=1; i<n; ++i) for(int d=-1; d<2; d+=2) for(int j=max(-d, 0); max(j+d, j)<m; ++j) for(int k=0; k<K; ++k) {
        if(dp[i-1][j+d][amod(k-aa[i][j],K)]+aa[i][j] > dp[i][j][k])
            dp[i][j][k]=dp[i-1][j+d][amod(k-aa[i][j], K)]+aa[i][j], from[i][j][k]=d;
    }

    vector<int> trace;
    int curr_j = 0, curr_k = 0, mx = -1;
    for(int j=0; j<m; ++j) if(dp[n-1][j][curr_k] > mx) curr_j = j;
    cout << mx << endl;

    for(int i=n-1; i>-1; --i)
        trace.push_back(curr_j), curr_j += from[i][j][0], curr_k = amod(curr_k-aa[i][curr_j], K);
    for(int i=0; i<(n>>1); ++i) swap(trace[i], trace[n-i-1]);


}

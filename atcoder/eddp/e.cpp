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

const ll mxN=1e5+5;
ll n,w;
ll temp_one, temp_two;

ll dp[mxN]; // the minimum weight to achieve dp[v] = min(dp[v], dp[v-curr_v]+curr_w);
bool visited[mxN];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,0x3f,sizeof(ll)*mxN);
    cin >> n >> w;
    
    dp[0]=0;
    for(ll i = 0;i < n;i++) {
        cin >> temp_one >> temp_two;
    
        for(ll value = mxN-temp_two; value >= 0; value--)
            min_self(dp[value+temp_two], dp[value]+temp_one);
    }
    
    ll temp_max = 0;
    for(ll i = 0; i<mxN; i++) {
        if(dp[i]<=w)
            max_self(temp_max,i);
    }
    cout << temp_max << endl;
    
    return 0;

}


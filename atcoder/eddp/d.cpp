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
const int mxN = 100005;

int n;
int W;
ll temp_one, temp_two;

ll dp[mxN];
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;

    for(int i = 0; i<n;i++) {
        cin >> temp_one >> temp_two;
        for(int w=W-temp_one;w>=0;w--)
            max_self(dp[w+temp_one],dp[w]+temp_two);
    }

    ll temp_max=0;
    for(int i=0;i<=W;i++)
        max_self(temp_max,dp[i]);
    cout << temp_max << endl;
            
    


    return 0;

}


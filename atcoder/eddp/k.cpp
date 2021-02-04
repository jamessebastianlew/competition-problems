
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
int k;
const int mxK = 1e5+5;

bool dp[mxK];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> values(100);
    cin >> n >> k;

    int temp;
    for(int i=0; i<n; ++i) cin >> values[i];

    for(int i=0; i<=k; ++i) {
        if(dp[i])
            continue;
        for(int j=0; j<n; ++j) {
            temp = values[j];
            if(i+temp<=k && !dp[i])
                dp[i+temp]=true;
        }
    }
    cout << (dp[k]?"First":"Second") << endl;
    return 0;

}


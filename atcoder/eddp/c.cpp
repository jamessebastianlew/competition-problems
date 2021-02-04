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
int temp[3];
int dp[3][2];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;

    while(n--) {
        for(int i = 0;i<3;i++) cin >> temp[i], swap(dp[i][1],dp[i][0]);
        for(int i = 0; i<3; i++) {
            for(int j=1;j<3;j++)
                max_self(dp[i][1],dp[(i+j)%3][0]+temp[(i+j)%3]);
        }
    }

    int temp_max;
    for(int i = 0; i < 3; i++)
        max_self(temp_max, dp[i][1]);
    cout << temp_max;

    return 0;

}


#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define pre(i, s, n) for(int i=s;i>n;i--)
#define preeq(i, s, n) for(int i=s;i>=n;i--)
#define MOD (int)10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n;
int dp[4];

//treat like 1-0 knapsack

// dp[i] the max amount of daisies you can save using i fences

int hip[3];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("hippoin.txt","r",stdin);
    freopen("hippoout.txt","w",stdout);
#endif
    vector<pair<int, int>> items(4); // {value, cost}

    cin >> n;
    rep(i, 0, 3)
        cin >> hip[i];

    items.pb({hip[0]-1, 1});
    items.pb({n-hip[2], 1});

    rep(i, 1, 3)
        items.pb({hip[i]-hip[i-1]-1,2});
    
    for(pair<int, int> x : items) preeq(i, 3, 0) {
        max_self(dp[i+x.second], dp[i]+x.first);
    }

    cout << dp[3] << endl;



    

    return 0;

}
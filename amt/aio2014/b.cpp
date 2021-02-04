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

int n, m, a, b;
const int MAX_N = 1e3+5;

vector<int> adj_m[MAX_N];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("hippoin.txt","r",stdin);
    freopen("hippoout.txt","w",stdout);
#endif


    cin >> n >> m >> a >> b;
    
    int temp_one, temp_two;
    rep(m,0,n) {
        cin >> temp_one >> temp_two;

        adj_m[temp_one].pb(temp_two);
        adj_m[temp_two].pb(temp_one);
    }

    return 0;

}
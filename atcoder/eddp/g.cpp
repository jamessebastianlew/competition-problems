
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

const int mxN = 1e5+5;

int n,m;
vector<int> adj_m;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue qq;
    adj_m.reserve(mxN);
    
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        cin >> temp_one >> temp_two;

        adj_m[temp_one].pb(temp_two);
    }
    for(int i=1;i<=n;++i) {
        adj_m[0].pb(i);
    }


    


    return 0;

}


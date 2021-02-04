
#include <bits/stdc++.h>

typedef long long ll;

#define vi vector<int>
#define pii pair<int, int>
#define ttt tuple<int, int, int>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxN=1e5+5;
int n;
vi adj_m[mxN];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp_one >> temp_two;
        adj[temp_one].pb(temp_two);
        adj[temp_two].pb(temp_one);
    }
    




    
    

    return 0;

}

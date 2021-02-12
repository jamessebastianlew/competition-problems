#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }

using namespace std;

const int mxN = 100001;

int n;
int a,b;
int temp;
vector<array<int,2>> adj[mxN];

ll longest_dist;
ll curr;

void dfs(int a, int from, ll dist) {
    amax(longest_dist, dist);
    for(array<int, 2> x : adj[a])
        if(x[0]!=from) dfs(x[0], a, dist+x[1]);
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n-1; ++i)
        cin >> a >> b >> temp, adj[a].pb({b,temp}), adj[b].pb({a,temp}), curr+=2*temp;

    dfs(1, 0, 0);
    cout << (curr - longest_dist) << endl;


    return 0;

}


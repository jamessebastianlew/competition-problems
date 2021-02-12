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

int V, E,a,b,x;

const int mxN = 1e5+5;
vector<int> adj[mxN];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for(int i=0; i<E; ++i)
        cin >> a >> b, adj[a].push_back(b);

    


    return 0;

}


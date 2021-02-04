#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
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

using namespace std;

const int mxV = 101;
const int mxE = 10001;
int V, E;

int edges[mxE][3];
int dists[mxV];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;

    memset(dists, 0x3f, sizeof(dists));
    for(int i=0; i<E; ++i)
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];

    dists[1] = 0;
    for(int i=0; i<V; ++i)
        for(int j=0; j<E; ++j)
            amin(dists[edges[j][2]], dists[edges[j][1]] + edges[j][0]);

    for(int i=1; i<=V; ++i)
        cout << (dists[i]>1000001?30000:dists[i]) << ' ';
    cout << endl;


    return 0;

}


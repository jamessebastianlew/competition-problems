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

const int mxN = 1e5+5;

int n;
int a[mxN][3];
vector<int> adj[mxN];
long long dp[mxN][3];   //dp[i][0] red, dp[i][1] green, dp[i][2], blue, the minimum
                        //cost for each respective colour using that node
                        //how do we find it? note that in a tree no outgoing edges
                        //will ever meet each otehr again, so they can chose any colour
                        //that is not the current nodes colour, so it should be the
                        //colour that costs the minimum for all of them and sum together
bool vis[mxN];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    memset(dp, 0x3f, sizeof(dp));

    for(int i=0; i<3; ++i)
        for(int j=1; j<=n; ++j)
            cin >> a[j][i];

    int temp_a, temp_b;
    for(int i=0; i<n-1; ++i) {
        cin >> temp_a >> temp_b;
        adj[temp_a].pb(temp_b);
        adj[temp_b].pb(temp_a);
    }

    ll curr_min = 0x3f3f3f3f3f3f3f3f;
    for(int i=1; i<=n; ++i)
        cout << dfs:

    return 0;

}


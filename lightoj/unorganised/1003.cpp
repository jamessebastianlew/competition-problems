
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int t;
int curr_unique;
const int mxN = 10000+5;

vector<vector<int>> adj_m;
string a, b;

bool has_cycle(int x, bitset<mxN>& visited) { 
    visited[x] = 1;
    for( int next : adj_m[x] )
        if(visited[next] || has_cycle(next, visited))
            return true;
    return false;
}

bool detect_cycle() {
    
    for(int i = 1; i<=curr_unique; ++i) {
        bitset<mxN> visited;
        if(has_cycle(i, visited))
            return true;
    }
    return false;
}
        
void solve() {
    cin >> n;

    curr_unique = 0;
    unordered_map<string, int> id;
    adj_m.clear();
    adj_m.resize(mxN);
    
    int aid;
    int bid;

    for(int i = 0; i<n; ++i) {
        cin >> a >> b;

        if(id.find(a)==id.end())
            id[a]=++curr_unique;
        if(id.find(b)==id.end())
            id[b]=++curr_unique;

        aid = id[a];
        bid = id[b];

        adj_m[aid].pb(bid);
    }

    if(detect_cycle())
        cout << "No";
    else
        cout << "Yes";
    cout << endl;
}




int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i = 1; i<=t; ++i)
        cout << "Case " << i << ": ", solve();

    return 0;
}


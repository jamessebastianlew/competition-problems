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
#define int long long

const int mxV = 1e5;
const int mxH = 1e5;
int n, k;
int temp;
int temp_s, temp_c;
vector<array<int, 2>> adj[mxV+mxH+1];
bool vis[mxV+mxH+1];
int costs[mxV+mxH+1];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, H;
    cin >> V >> H;

    // total of V+H nodes
    for(int i=1; i<=H; ++i) {
        cin >> temp_c >> temp_s;
        while(temp_s--)
            cin >> temp, adj[V+i].pb({temp, temp_c}), adj[temp].pb({V+i, temp_c});
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> qq;
    qq.push({0,1});

    while(!qq.empty()) {
        array<int, 2> curr = qq.top();
        int curr_node = curr[1];
        int curr_cost = curr[0];
        qq.pop();

        if(vis[curr_node])
            continue;
        vis[curr_node] = true;

        costs[curr_node] = curr_cost;

        for(array<int, 2> node : adj[curr_node])
            if(!vis[node[0]])
                qq.push({curr_cost+node[1], node[0]});
    }

    cout << (costs[V]>>1) << endl;
    return 0;

}


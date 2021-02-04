
#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxn = 2e3+1;

int n;
vector<int> adj[mxn];

int in[mxn];
int depth[mxn];

int main() {
    // tree
    // things with the same depth?

    cin >> n;
    int temp;
    for(int i=1; i<=n; ++i) {
        cin >> temp;
        if(temp==-1) continue;
        adj[temp].push_back(i);
        ++in[i];
    }

    queue<array<int,2>> qq;
    for(int i=1; i<=n; ++i)
        if(!in[i]) qq.push({i, 1});

    int max_depth = 0;
    while(!qq.empty()) {
        array<int, 2> u = qq.front();
        qq.pop();
        amax(max_depth, u[1]);

        for(int v : adj[u[0]])
            if(!(--in[v])) qq.push({v, u[1]+1});
    }

    cout << max_depth << endl;


    return 0;
}

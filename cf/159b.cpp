
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

const int mxval = 1e3+5;
unordered_map<array<int,2>, int> caps;
multiset<array<int,2>> bmatch[mxn];

int n,m;
int main() {
    cin >> n >> m;
    int a,b;
    for(int i=0; i<n; ++i) cin >> a >> b, bmatch[b].insert(a);

    //perfects
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        if(
    }

    return 0;
}

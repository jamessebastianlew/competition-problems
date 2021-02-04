
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

const int mxN =1e5+5;
multiset<int> temp[mxN];

int val[mxN];
int gar[mxN];

int main() {
    cio();
    int n,q;
    int a,b;
    cin >> n >> q;;
    for(int i=0; i<n; ++i)
        cin >> a >> b, val[i] = a, gar[i] = b, temp[b].insert(val[i]);

    for(int i=0; i<q; ++i) {
        cin >> a >> b;
        temp[gar[a]].erase(val[a]);
        gar[a] = b;
        temp[gar[a]].insert(val[a]);
    }
}
        
        



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

const int mxn = 2e5+5;
int n, k;
int skl[mxn];
int sskl[mxn];
int cnt[mxn]; // could have but quarreling
int cnt2[mxn]; // could have in total
int main() {
    cio();
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> skl[i], sskl[i] = skl[i];
    int u,v;
    while(k--) {
        cin >> u >> v;
        if(skl[u] > skl[v]) ++cnt[u];
        else if(skl[v] > skl[u]) ++cnt[v];
    }
    sort(sskl+1, sskl+n+1);
    for(int i=1; i<=n; ++i) {
        int lo = 0, hi = n+1;
        while(lo+1 < hi) {
            int mid = (lo+hi)>>1;
            if(sskl[mid] < skl[i]) lo = mid;
            else hi = mid;
        }
        cnt2[i] = lo;
    }
    for(int i=1; i<=n; ++i) cout << (cnt2[i] - cnt[i]) << ' ';

    return 0;
}

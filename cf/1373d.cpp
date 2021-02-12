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

const ll mxn = 2e5+5;
ll aa[mxn];

ll n,t;
void solve() {
    cin >> n;

    ll mx = 0;
    ll tot = 0;
    for(int i=0; i<n; ++i) cin >> aa[i];
    for(int i=0; i<n; i+=2) tot+=aa[i];

    ll sm = 0;
    for(int i=1; i+1<n; i+=2)
        sm=max(sm+aa[i]-aa[i+1], aa[i]-aa[i+1]), amax(mx, sm);
    sm = 0;
    for(int i=0; i+1<n; i+=2)
        sm=max(sm+aa[i+1]-aa[i], aa[i+1]-aa[i]), amax(mx, sm);
    cout << (tot + mx) << endl;
}
int main() {
    cio();
    cin >> t;
    while(t--) solve();

    return 0;
}

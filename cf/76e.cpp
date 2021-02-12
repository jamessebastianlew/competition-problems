
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

const ll mxn = 1e5+5;
ll n;
ll x[mxn];
ll y[mxn];
ll xs[mxn];
ll ys[mxn];

int main() {
    cio();
    cin >> n;
    for(ll i=1; i<=n; ++i)
        cin >> x[i] >> y[i], xs[i] = x[i]*x[i], ys[i] = y[i]*y[i], x[i]+=x[i-1], y[i]+=y[i-1], xs[i]+=xs[i-1], ys[i]+=ys[i-1];

    ll total = 0;
    for(ll i=1; i<=n; ++i) {
        total+=(i-1)*(xs[i]-xs[i-1]) - 2 * (x[i] - x[i-1]) * x[i-1] + xs[i-1];
        total+=(i-1)*(ys[i]-ys[i-1]) - 2 * (y[i] - y[i-1]) * y[i-1] + ys[i-1];
    }
    cout << total << endl;


        


    return 0;
}

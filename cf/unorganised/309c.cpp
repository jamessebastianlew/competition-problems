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
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const ll mxn = 1e6+5;
ll n, m;
ll aa[mxn];
ll bb[mxn];
ll lgg[64];

int main() {
    cio();
    cin >> n >> m;

    for(int i=0; i<n; ++i) {
        cin >> aa[i];
        for(int j=0; j<63; ++j) lgg[j]+=((aa[i]>>j) & 1);
    }

    for(int i=0; i<m; ++i) cin >> bb[i];
    sort(bb, bb+m);

    ll cnt = 0;
    ll k;
    for(int i=0; i<m; ++i) for(int j=bb[i]; j<63; ++j)
        if(lgg[j]>0) { for(k=bb[i+1], ++cnt, --lgg[j]; i+1<m && k<j; ++k) ++lgg[k];
            break;
        }

    cout << cnt << endl;

    return 0;
}

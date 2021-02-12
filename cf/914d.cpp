#include <bits/stdc++.h>

typedef long long ll;

#define cio() ios::sync_with_stdio(0); cin.tie(0);
#ifndef FLOSH
    #define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
    #define fio(in, out) cio()
#endif
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxn = 5e5+1;
int n;

int aa[mxn];
int st[4 * mxn];

#define lc (id << 1)
#define rc (id << 1 | 1)

void build(int id=1, int l=0, int r=n) {
    if(l == r-1) { st[id] = aa[l]; return; }
    int mid = (l + r) >> 1;
    build(lc, l, mid); build(rc, mid, r);
    st[id] = __gcd(st[lc], st[rc]);
}

int num_bad_leaves(int lo, int hi, int x, int id=1, int l=0, int r=n) {
    if(r <= lo or l >= hi) return 0;
    if(lo <= l and r <= hi and st[id] % x == 0) { return 0; }
    if(lo <= l and r <= hi and r-l == 1 and st[id] % x != 0) return 1;
    int cnt = 0;
    int mid = (l + r) >> 1;
    cnt += num_bad_leaves(lo, hi, x, lc, l, mid);
    if(cnt > 1) return cnt;
    cnt += num_bad_leaves(lo, hi, x, rc, mid, r);
    return cnt;
}

bool query(int lo, int hi, int x) {
    return num_bad_leaves(lo, hi, x) <= 1;
}

void update(int pos, int val, int id=1, int l=0, int r=n) {
    if(r <= pos or l > pos) return;
    if(r-l == 1 && l == pos) { st[id] = val; return; }
    int mid = (l + r) >> 1;
    update(pos, val, lc, l, mid); update(pos, val, rc, mid, r);
    st[id] = __gcd(st[lc], st[rc]);
}

int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    int q;
    cin >> q;
    int type, a, b, x;
    while(q--) {
        cin >> type;
        if(type == 1) cin >> a >> b >> x, --a, --b, cout << (query(a, b+1, x) ? "YES" : "NO") << endl;
        else cin >> a >> x, --a, update(a, x);
    }
    return 0;
}

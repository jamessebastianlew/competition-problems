#include <bits/stdc++.h>

using namespace std;

const int mxN = 3e5+5;

int n;
void amin(array<int,2>& a, array<int,2> b) { a=a<b?a:b; }

array<int,2> st[4*mxN];
array<int,2> dd[4*mxN]; // time, person
int aa[mxN];

#define lc id<<1
#define rc id<<1|1

void push(int id) {
    amin(st[lc], dd[id]); amin(st[rc], dd[id]);
    amin(dd[lc], dd[id]); amin(dd[rc], dd[id]);
}

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { st[id]={0x3f3f3f3f,0}; dd[id] = {0x3f3f3f3f, 0}; return; }
    int mid = (l+r)>>1;
    build(lc, l, mid); build(rc, mid, r);
    st[id] = st[lc];
    dd[id] = dd[lc];
}

void update(int lo, int hi, array<int,2> val, int id=1, int l=0, int r=n) {
    if(r<=lo || l>=hi) return;
    if(l>=lo && r<=hi) { amin(st[id], val); amin(dd[id], val); return; }
    int mid = (l+r)>>1;
    push(id);
    update(lo,hi,val,lc,l,mid); update(lo,hi,val,rc,mid,r);
    st[id] = min(st[lc], st[rc]);
}

void pushall(int id=1, int l=0, int r=n) {
    if(r-l<2) {cout << st[id][1] << ' '; return; }
    push(id);
    int mid = (l+r)>>1;
    pushall(lc, l, mid); pushall(rc, mid, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;
    build();

    int a,b,x;
    for(int i=0; i<q; ++i) {
        cin >> a >> b >> x;
        if(x!=b) update(x, b, (array<int,2>){i, x});
        update(a-1, x-1,(array<int,2>){i, x}); 
    }
    pushall();
    cout << '\n';

    return 0;
}

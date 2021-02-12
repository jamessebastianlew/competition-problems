#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

int n, q;
int st[2*mxN];
bool even[2*mxN];
int dd[2*mxN];
int aa[mxN];

#define lc id<<1
#define rc id<<1|1

void build(int id=1, int l=0, int r=n) {
    if(r-l<2) { even[id]=true; st[id]=aa[l]; return; }
    int mid = (l+r)>>1;
    build(lc,l,mid); build(rc,mid,r);
    even[id] = !even[lc];
    if(even[id]) st[id] = st[lc] ^ st[rc];
    else st[id] = st[lc]|st[rc];
}

void update(int p, int b, int id=1, int l=0, int r=n) {
    if(l>p || r<=p) return;
    if(r-l<2 && l==p) { st[id] = b; return; }
    int mid = (l+r)>>1;
    update(p,b,lc,l,mid); update(p,b,rc,mid,r);
    if(even[id]) st[id] = st[lc] ^ st[rc];
    else st[id] = st[lc]|st[rc];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    n=1<<n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    build();

    int a,b;
    while(q--) {
        cin >> a >> b;
        update(a-1,b);
        cout << st[1] << endl;
    }

    return 0;
}

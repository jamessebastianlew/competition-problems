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

const int mxn = 1e5+5;
const int bs = 300;

int n, q;
int aa[mxn];
int bb[mxn];
int id[mxn];

int main() {
    cio();
    cin >> n >> q;

    for(int i=0; i<n; ++i) cin >> aa[i], bb[i] = aa[i];
    for(int l=0, r=min(bs,n), cntr=0; l<n; l+=bs, r=min(r+bs,n),++cntr) {
        sort(bb+l, bb+r); 
        for(int i=l; i<r; ++i) id[i] = cntr;
    }

    char type;
    int a, b, x;

    while(q--) {
        cin >> type >> a >> b;
        if(type=='M') {
            --a;
            aa[a] = b;
            int l = id[a]*bs, r = min(l+bs, n);
            for(int i=l; i<r; ++i) bb[i] = aa[i];
            sort(bb+l, bb+r);
        } else {
            cin >> x;
            --a; --b;

            int cnt = 0;
            for(int i=a; i<min({(id[a]+1)*bs, b+1, n}); ++i)
                if(aa[i] <= x) ++cnt;
            if(id[a] == id[b]) { cout << cnt << endl; continue; }

            for(int i=id[b]*bs; i<=b; ++i) if(aa[i] <= x) ++cnt;
            if((id[b]) - (id[a]) < 2) { cout << cnt << endl; continue; }

            int st = (id[a]+1)*bs;
            int en = id[b]*bs;

            for(int l=st*bs, r = l+bs; r<=en; l+=bs, r+=bs) {
                int lo = l-1, hi = r;
                while(lo+1<hi) {
                    int mid = (lo+hi)>>1;
                    if(aa[mid] <= x) lo=mid;
                    else hi=mid;
                }
                cnt+=lo-l+1;
            }
            cout << cnt << endl;
        }
    }
        
    return 0;
}

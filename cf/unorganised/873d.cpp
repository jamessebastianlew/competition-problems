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

const int mxn = 1e5+5;
const int mxk = 2e5+5;
int n, k;

int aa[mxn];
int cnt = 1;

void flip(int l, int mid, int r) {
    for(int i=l, j = mid; i<mid; ++i, ++j) {
        int temp = aa[i];
        aa[i] = aa[j];
        aa[j] = temp;
    }
    cnt+=2;
}
    
void calc_merge(int l, int r) {
    if(r-l==1) return;

    int mid = (l+r)>>1;
    if(cnt < k) flip(l, mid, r);

    calc_merge(l, mid);
    calc_merge(mid, r);
}

int main() {
    cio();
    cin >> n >> k;
    for(int i=0; i<n; ++i) aa[i] = i+1;
    calc_merge(0, n);
    if(cnt!=k) { cout << -1 << endl; return 0; }
    for(int i=0; i<n; ++i) cout << aa[i] << ' ';


    return 0;
}

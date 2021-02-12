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
int amod(T a, T b) { if(a >= b) return a-b; return a;}

using namespace std;

const int mxn = 35;
const int mxs = 2e6+5;

int n, m;
int aa[mxn], bb[mxs], cc[mxs];
int lb, lc;

void genperms(int l, int r, int sm, int& len, int* arr) {
    if(!(l<r)) { arr[len++] = sm; return; }
    genperms(l+1, r, sm, len, arr);
    genperms(l+1, r, (sm+aa[l])%m, len, arr);
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; ++i) cin >> aa[i];
    int mid = n>>1;

    genperms(0, mid, 0, lb, bb);
    genperms(mid, n, 0, lc, cc);

    sort(bb, bb+lb);
    int mx = 0;
    for(int i=0; i<lc; ++i) {
        //find split point something + bb[i] == m
        int lo = -1, split = lb;
        while(lo+1 < split) {
            int mid_two = (split+lo)>>1;
            if(bb[mid_two] + cc[i] >= m) split = mid_two;
            else lo = mid_two;
        }
        amax(mx, amod(bb[lb-1]+cc[i], m));
        if(split==lb || split==0) continue;
        amax(mx, amod(bb[split-1]+cc[i], m));
    }
    cout << mx << endl;

    return 0;
}

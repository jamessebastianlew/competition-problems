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
int n;
int aa[mxn];
//dp or greedy
//greedY!

int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    int mn = 0x3f3f3f3f;
    for(int i=-1; i<2; ++i) for(int j=-1; j<2; ++j) {
        int total = i!=0;
        total += j!=0;
        int dist = aa[1]+j - (aa[0]+i);
        int prev = aa[1]+j;
        bool prf = 1;
        for(int k=2; k<n; ++k)
            if(abs(aa[k] - (prev + dist)) < 2) {
                if(abs(aa[k] - (prev+dist))!=0) ++total;
                prev = prev + dist;
            } else { prf = 0; break; }
        if(prf) amin(mn, total);
    }
    if(mn==0x3f3f3f3f) cout << -1 << endl;
    else cout << mn << endl;






    return 0;
}

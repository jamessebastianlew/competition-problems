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
#define int long long

const int mxn = 2e5+5;
int n, m;
int aa[mxn];

#undef int
int main() {
#define int long long

    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> aa[i], aa[i]+=aa[i-1];
    int nm;
    while(m--) {
        cin >> nm;
        int lo=-1, hi=n+1;
        while(lo+1 < hi) {
            int mid = (lo+hi)>>1;
            if(nm - aa[mid] > 0) lo = mid;
            else hi = mid;
        }
        cout << (lo+1) << ' ' << (nm - aa[lo]) << endl;

    }
    
    return 0;
}

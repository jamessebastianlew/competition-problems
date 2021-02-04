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

const int mxn = 1e5+5;
int n, k;

int need[mxn];
int have[mxn];

#undef int
int main() {
#define int long long
    // make with ingredients
    // then make one cookie minimum magic powder
    // then you can decide how many more she can make with the leftovers
    cio();
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> need[i];
    for(int i=0; i<n; ++i) cin >> have[i];

    int lo = 0, hi = 2e9+1;
    while(lo+1 < hi) {
        int mid = (lo+hi)>>1;
        int cocaine = k;
        for(int i=0; i<n; ++i) {
            int total = need[i] * mid;
            cocaine -= max(total - have[i], 0ll);
            if(cocaine<0) break;
        }
        if(cocaine < 0ll) hi = mid;
        else lo = mid;
    }

    cout << lo;
    return 0;
}

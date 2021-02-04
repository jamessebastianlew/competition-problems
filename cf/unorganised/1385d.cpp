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

int t, n;
string s;

int get_good(int l, int r, char rep) {
    if(r-l==1) return (s[l]==rep?0:1);
    
    int mid = (l+r)>>1;
    int cf = 0, cl = 0;
    for(int i=l; i<mid; ++i) if(s[i]!=rep) ++cf;
    for(int i=mid; i<r; ++i) if(s[i]!=rep) ++cl;

    return min(cl+get_good(l,mid,rep+1), cf+get_good(mid,r,rep+1));
}

void solve() {
    cin >> n >> s;
    cout << (get_good(0, n, 'a')) << endl;
}

int main() {
    cio();
    cin >> t;
    while(t--) solve();

    return 0;
}

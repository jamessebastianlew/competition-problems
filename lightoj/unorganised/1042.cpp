
#include <bits/stdc++.h>

typedef long long ll;

#define CASE(i) cout << "Case " << i << ": "
#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

void solve() {
    cin >> n;
    int finding = __builtin_popcount(n);
    
    int ans = n;
    ans+=n&-n;
    int need =finding - __builtin_popcount(ans);
    for(int i = 0; need > 0; ++i) {
        if(!( ans & (1 << i) ))
            --need, ans|=1<<i;
    }
    cout << ans << endl;

}





int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    for(int i=1; i<=t; ++i)
        cout << "Case " << i << ": ", solve();


    


    return 0;

}


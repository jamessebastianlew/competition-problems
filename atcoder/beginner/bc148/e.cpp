
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

ll n;

        
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    if((n&1)) {
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    for(ll i=10; i <= n; i*=5) {
        cnt+=n/i;
    }
    cout << cnt << endl;
    return 0;

}

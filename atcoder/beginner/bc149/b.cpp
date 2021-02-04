#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(ll i=s;i<n;i++)
#define repeq(i,s,n) for(ll i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(ll& a, ll b) { a=a>b?a:b; }
void min_self(ll& a, ll b) { a=a<b?a:b; }

using namespace std;

ll t, a, k;
ll temp;

int main() {
    cin >> t >> a >> k;

    ll temp_t = t;

    t = max(0LL, t-k);
    k = max(k-temp_t, 0LL);
    a = max(a-k, 0LL);

    cout << t << ' ' << a << endl;
    
    return 0;
}
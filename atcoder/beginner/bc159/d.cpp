
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(ll i=s;i<n;i++)
#define repeq(i,s,n) for(ll i=s;i<=n;i++)
#define poiu(n) for(ll i=0; i < n; i++)
#define MOD (ll)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

ll n;
ll a[200005];
ll total[200005];


int main() {
    vector<ll> unique;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    unique.reserve(200005);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(total[a[i]]==0)
            unique.pb(a[i]);
        total[a[i]]++;
    }

    ll total_combos = 0;
    ll temp;
    for(ll x : unique)
        temp=total[x], total_combos+=temp*(temp-1)/2;
    
    for(ll i=0; i<n; i++) {
        cout << total_combos-total[a[i]]+1 << endl;
    }
    return 0;

}


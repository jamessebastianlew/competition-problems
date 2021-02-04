
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(ll i=s;i<n;i++)
#define repeq(i,s,n) for(ll i=s;i<=n;i++)
#define MOD (ll)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

ll n;
ll a, b;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> a >> b;

    cout << (a*b)/__gcd(a,b) << endl;
    

    return 0;

}

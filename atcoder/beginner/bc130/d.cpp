#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(ll i=s;i<n;i++)
#define repeq(i,s,n) for(ll i=s;i<n+1;i++)
#define MOD 10e9+7

void max_self(ll& a, ll b) { a=a>b?a:b; }
void min_self(ll& a, ll b) { a=a<b?a:b; }

const ll MAX_N = 1e5+5;

using namespace std;

ll n, k;

ll prefs[MAX_N];
ll num_ways;

ll ran(ll l, ll r) {return prefs[r]-prefs[l-1];}

int main() {

    cin >> n >> k;

    ll l = 1;
    ll r = 1;

    repeq(i,1,n) {
        cin >> prefs[i];
        prefs[i]+=prefs[i-1];
    }

    while( r <= n ) {
        if(ran(l,r) < k) {
            r++;
            continue;
        }

        num_ways += n-r+1LL;
        l++;
    }

    cout << num_ways << endl;
    




    return 0;
}
#include <bits/stdc++.h>

typedef long long ll;

#define debug(something) something
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
#define int long long

int n;

const int mxN = 5e5+5;
int sm;
int need;
int a[mxN];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], sm += a[i];
    if(sm%3!=0) {cout << 0 << endl; return 0;}
    sm/=3;
    int runsm = 0, smcnt = 0, total = 0;
    for(int i = 1; i<=n-1; ++i) {
        runsm+=a[i];
        if(runsm==2*sm) total+=smcnt;
        if(runsm==sm) ++smcnt;
    }
    cout << total << endl;

    return 0;

}


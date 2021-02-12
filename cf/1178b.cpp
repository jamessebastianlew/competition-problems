
#include <bits/stdc++.h>

typedef long long ll;

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

int pref_sums[1000005];

int wows;
int wos;
int prev_ws;
string s;


#undef int 
int main() {
#define int long long

    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    cin >> s;
    n = poius(s);
    for(int i=1; i<n; ++i) {
        if(s[i]=='v' && s[i-1]=='v') ++prev_ws, wows+=wos;
        else if(s[i]=='o') wos+=prev_ws;
    }
    cout << wows << endl;
    */
    //My implementation
    //
    cin >> s;
    n = poius(s);
    for(int i=1; i<n; ++i)
        pref_sums[i] = pref_sums[i-1]+(int)(s[i]=='v'&&s[i-1]=='v');

    ll ans = 0;
    for(int i = 1; i<n; ++i)
        if(s[i]=='o') ans+=((ll)pref_sums[i])*(pref_sums[n-1]-pref_sums[i]);
    cout << ans << endl;

    return 0;
}


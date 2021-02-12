
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, q;
string s;

int pref_sums[100005];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    cin >> q;
    n = s.size();

    for(int i=1; i<n; ++i)
        pref_sums[i]=pref_sums[i-1]+(int)(s[i-1]==s[i]);

    int lo, hi;
    while(q--) {
        cin >> lo >> hi;
        cout << (pref_sums[hi-1]-pref_sums[lo-1]) << endl;
    }

    return 0;


}


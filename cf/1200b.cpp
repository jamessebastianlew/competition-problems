
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

int n, m, k;
int t;

int a[101];

int temp;

void solve() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];

    for(int i=1; i<n; ++i) {
        m+=min(a[i], a[i]-(a[i+1]-k));
        if(m<0) { cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;
}




int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    
    while(t--)
        solve();

    return 0;

}



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

int n, t;

int a[100005];
void solve() {
    cin >> n;

    int total = 0;
    for(int i = 1; i<=n; ++i) cin >> a[i], total+=a[i];

    int max_no_end = a[1];
    int curr = a[1];
    for(int i=2; i<n; ++i)
        curr = max(a[i], curr+a[i]), amax(max_no_end, curr);
    int max_no_start = a[2];
    curr = a[2];
    for(int i=3; i<=n; ++i)
        curr = max(a[i], curr+a[i]), amax(max_no_start, curr);

    cout << (total>max(max_no_start, max_no_end)?"YES":"NO") << endl;
}



#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    
    while(t--)
        solve();

    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

#define fortests(i, t) for(int i = 1; i<=t; ++i) cout << "Case " << i << ": "
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

int n;
int t;

void solve() {
    cin >> n;
    int temp = 0;
    int sm = 0;
    while(n--)
        cin >> temp, sm+=(temp>0?temp:0);
    cout << sm << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=1; i<=t; ++i)
        cout << "Case " << i << ": ", solve();

    


    return 0;

}


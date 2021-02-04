
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

int n;
int q;

void solve() {
    cin >> n;
    cout << min(n,10) << ' ';
    n-=min(n,10);
    cout << n << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> q;
    while(q--)
        solve();
    


    return 0;

}


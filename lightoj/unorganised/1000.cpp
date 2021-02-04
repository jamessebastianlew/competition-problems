
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
int a, b;

void solve() {
    cin >> a >> b;
    cout << (a+b) << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    for(int i = 1; i<=q; ++i)
        cout << "Case " << i << ": ", solve();
    


    return 0;

}


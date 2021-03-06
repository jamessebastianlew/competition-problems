
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
int t;
int base;

void solve() {
    cin >> n >> base;
    int cnt = 1;
    double fc=1;
    for(int i = 1; i<= n; ++i) {
        fc*=i;
        while(fc>=base)
            fc/=base, ++cnt;
    }
    cout << cnt << endl;
}
        


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=1; i<=t; ++i)
        cout << "Case " << i << ": ", solve();



    


    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define INF 1000000009
#define LLINF 1000000000000000009
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int q;

const int mxN = 10000000;

int process(int temp) {
    if(temp%4==0)
        return temp/4;
    return 0;
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> q;
    while(q--) {
        cin >> n;
        bool ok = true;
        for(int x : {1,2,3,5,7,11})
            ok&=(x!=n);

        if(!ok)
            cout << -1;
        else
            cout << (n/4 - (n&1));
        cout << endl;
    }

    return 0;

}


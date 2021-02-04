
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

int n, m;
int t;
    
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    int a, b;
    for(int _=1; _<=t; ++_) {
        cin >> a >> b;
        bool black = false;
        int cnt = 0;
        for(int i = 0; i<m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(black)
                    ++cnt;
                black^=true;
            }
        }
        int temp = max(cnt, a*b-cnt);
        cout << "Case " << _ << ": " << temp << endl;
    }

    return 0;

}


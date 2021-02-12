
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

string s, t;

void solve() {
    int cnt = 0;
    for(int i = 0; i<n; ++i) {
        if(s[i]!=t[i]) {
            if(i+1 < n && s[i+1]==t[i] && s[i] == t[i+1]) ++i;
            ++cnt;
        }
    }
    cout << cnt << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> s >> t;

    solve();
    


    return 0;

}


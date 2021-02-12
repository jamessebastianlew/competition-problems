#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, m;
string s;
set<string> known;

int main() {
    cio();

    cin >> n >> m;
    int both = 0;
    for(int i=0; i<n; ++i)
        cin >> s, known.insert(s);
    for(int i=0; i<m; ++i) {
        cin >> s;
        if(known.count(s)) ++both;
    }

    int temp = (both+1)>>1;
    n -= both-temp;
    m -= temp;
    if(n>m) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

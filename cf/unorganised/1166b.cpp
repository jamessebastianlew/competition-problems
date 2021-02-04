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

const int mxn = 1e5+5;
vector<vector<char>> s;
int n, m;
int k;
int nm[mxn];

string vowels = "aeiou";

void solve() {
    s = vector(n, vector<char>(m));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        s[i][j] = vowels[(i+j)%5];
}

int main() {
    cio();
    cin >> k;
    bool yes = false;
    for(int j=5; j*j<=k; ++j)
        if(k%j==0) {yes = true; n=j, m=k/j; solve(); break; }

    if(!yes) { cout << -1; return 0; }
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cout << (char)s[i][j];
    cout << endl;
    
    return 0;
}

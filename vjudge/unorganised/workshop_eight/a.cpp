
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

const int mxn = 50;
int n;
int aa[mxn];
map<int, int> freq;
bool use[mxn];
int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i]; 
    for(int i=0; i<n; ++i) ++freq[aa[i]];
    int cnt = 0;
    for(int i=0; i<n; ++i) if(!(--freq[aa[i]])) use[i] = true, ++cnt;
    cout << cnt << endl;
    for(int i=0; i<n; ++i) if(use[i]) cout << aa[i] << ' ';
    return 0;
}


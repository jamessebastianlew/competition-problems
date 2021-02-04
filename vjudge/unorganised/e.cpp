
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

const int mxn = 101;
ll prefq[mxn];

string s;
int main() {
    cin >> s;
    const int n = s.size();

    ll cnt = 0;
    for(int i=1; i<=n; ++i)
        prefq[i] = prefq[i-1]+(s[i-1]=='Q');
    for(int i=1; i<=n; ++i)
        if(s[i-1]=='A') 
            cnt += prefq[i] * (prefq[n] - prefq[i]);

    cout << cnt;

    
    return 0;
}

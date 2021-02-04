
#include <bits/stdc++.h>

typedef long long ll;

#ifndef FLOSH
#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
#define fio(in, out)
#endif
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

int main() {
    cio();
    ll n, m;
    cin >> n >> m;
    int res = 1;
    int pow = 10;
    int oldm = m;
    m = m * m;
    for(int red = n; red > 0; red >>= 1) {
        if(red&1) res = res * pow % m;
        pow = pow * 10 % m;
    }
    cout << res << endl;
    cout << res % oldm << endl;

    return 0;
}

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

long long n, m;

long long pow(long long x, long long y) {
    long long temp = 1;
    for(int i=0; i<y; ++i) temp *= x;
    return temp;
}

int main() {
    cio();
    cin >> n >> m;
    for(int n=0; n<18; ++n) {
        cout << (long long)( pow(10, n) ) % m << endl;
    }

    return 0;
}

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

int r, b, s, needsr, needsb;

int main() {
    fio("baublesin.txt", "baublesout.txt");
    cin >> r >> b >> s >> needsr >> needsb;

    int bs = s;
    int rs = s;
    
    // make the order
    int addb = max(needsb - b, 0);
    int addr = max(needsr - r, 0);
    r += addb;
    b += addr;

    int needss = addb + addr;
    s -= needss;

    if(s < 0) { cout << 0 << endl; return 0; }
    cout << min(max(s + r - (needsr-1), 0), max(s + b - (needsb-1), 0)) << endl;

    return 0;
}

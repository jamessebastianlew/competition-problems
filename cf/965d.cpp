#include <bits/stdc++.h>

typedef long long ll;

#define cio() ios::sync_with_stdio(0); cin.tie(0);
#ifndef FLOSH
    #define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#else
    #define fio(in, out) cio()
#endif
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxw = 1e5;
int a[mxw];
int curr[mxw];
int l, w;

// idea: populate the rocks as much as possible
// propogate the population and kill the ones
// who don't make it

int main() {
    cio();
    cin >> w >> l;
    for(int i=0; i<w-1; ++i) cin >> a[i] << endl; a[w-1] = 2e9;
    for(int i=0; i<l; ++i) curr[mxw] = a[i];

    int front = 0, end = l-1;
    while(front < w-1) {

    }
    // prop
    
    

    return 0;
}



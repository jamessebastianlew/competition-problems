#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }

using namespace std;

int n;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cnt_one, cnt_two, x, y;
    cin >> cnt_one >> cnt_two >> x >> y;

    int lcm = x*y;
    // all common multiples will be a multiple of the lcm
    // number of numbers excluded will be curr/x + curr/y - curr/lcm
    // binary search until you curr - num excluded = cnt1+cnt2
    
    int lo = 1, hi = 1e9+5;
    while(lo+1 < hi) {
        int curr = (lo+hi)>>1;
        int num_first = curr - curr/x+1;
        int num_second = curr - curr/y+1;

        cout << curr << ' ' << total << ' ' << num_first << ' ' << num_second << endl;

        if(num_first>=cnt_one && num_second>=cnt_two)
            hi = curr;
        else
            lo = curr;
    }

    cout << hi << endl;



    return 0;

}


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

const int mxn = 8; 
int n;
ll aa[mxn];

int sv[mxn];

// smallest divisor trees for lesser numbers

ll gcd(ll a, ll b) {
    while(b > 0) {
        int tmp = a%b;
        a = a/b;
        b = tmp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}

ll gcd_dnc(ll lst[], int l, int r) { 
    if(l+1 == r) return lst[l];
    int mid = (l+r)>>1;
    return gcd(gcd_dnc(lst, l, mid),gcd_dnc(lst, mid, r));
}

// dp divisors, min divisors of i = min divisors i-x + i-(i-x)
//
int main() {
    cio();

    cin >> n;
    ll tmp, mlt1
    for(int i=0; i<n; ++i) cin >> aa[i];
    

    root = 





    return 0;
}

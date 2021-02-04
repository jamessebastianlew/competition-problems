
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

const long long mxn = 1e5+5;
long long n,h,k;
long long aa[mxn];
int main() {
    cio();
    cin >> n >> h >> k;
    for(long long i=0; i<n; ++i) cin >> aa[i];

    long long total = 0;
    long long curr = 0;
    long long i=0;
    while(i<n) {
        while(i<n && curr + aa[i] <= h) curr+=aa[i], ++i;
        total+=curr/k;
        curr = curr % k;
        if(!(i==n) && curr + aa[i] > h && curr!=0) curr = 0, ++total;
    }

    if(curr > 0) total+=(curr+k-1)/k;
    cout << total << endl;

    return 0;
}

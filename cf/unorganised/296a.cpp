
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

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    sort(aa, aa+n);

    int prf = 0;
    for(int i=1; i<n; ++i) if(aa[i]==aa[i-1]) prf = 1;
    

    return 0;
}

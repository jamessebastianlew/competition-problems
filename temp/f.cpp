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
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;
#define int long long

const int mxn = 501;
int aa[mxn];
int n;

#undef int
int main() {
#define int long long
    cio();
    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i];
    int mx_ind = 0;
    for(int i=0; i<n; ++i) if(aa[i] > aa[mx_ind]) mx_ind = i;
    int left = mx_ind-1;
    int right = mx_ind+1;
    int ans = 0;
    while(left >= 0) ans += aa[left] * aa[mx_ind] - (left == 0 ? 0 : aa[left-1]), --left;
    while(right < n) ans += aa[right] * aa[mx_ind] - (right == n-1 ? 0 : aa[right+1]), --right;
    ans += aa[mx_ind];
    cout << ans << endl;

    return 0;
}

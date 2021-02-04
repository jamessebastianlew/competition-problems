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

string s;
const int mxn = 51;
bool dp[mxn][mxn];

int main() {
    cio();
    cin >> s;
    const int n = s.size();

    for(int l=n-1; l>=0; --l) for(int r=l; r<n; ++r) {
        if(r==l) { dp[l][r] = true; continue; }
        else if(r==l+1) {
            if(s[l] == s[r]) dp[l][r] = true;
            continue;
        }
        if(s[l]==s[r] && dp[l+1][r-1]) dp[l][r] = true;
    }
    
    int mx = 0;
    for(int l=0; l<n; ++l) for(int r=l; r<n; ++r)
        if(!dp[l][r]) amax(mx, r-l+1);

    cout << mx << endl;

    return 0;
}

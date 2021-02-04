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

const int mxn = 1e5+5;
int pairs[mxn][2];
int t, n;

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> pairs[i][0] >> pairs[i][1];

    int max_left = INT_MIN, min_right = INT_MAX;
    for(int i=0; i<n; ++i)
        amax(max_left, pairs[i][0]), amin(min_right, pairs[i][1]);
    
    cout << (max((max_left - min_right), 0)) << endl;
}

int main() {
    cio();
    cin >> t;
    for(int i=0; i<t; ++i) solve();
    return 0;
}

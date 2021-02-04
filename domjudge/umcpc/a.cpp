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
void amod(T& a, T b) { a=a>=b?a-b:a; }

using namespace std;

const int mxN = 1e5+5;

int dp[mxN];
vector<array<int, 2>> temp;

int main() {
    int a;
    cin >> a;
    dp[0] = 1;
    int n=2000;
    for(int i=0; i<n; ++i) for(int j=n; j; --j) {
        dp[j] = (dp[j]+dp[j-1]) % mod;
        if(dp[j] == a)
            temp.push_back({i+1, j});
    }
    sort(temp.begin(), temp.end(), [](auto a, auto b) {
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
            });

    for(int i=0; i<(int)temp.size(); ++i)
        cout << temp[i][0] << ' ' << temp[i][1] << endl;

    return 0;
}


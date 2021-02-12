
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

int temp[27];
string s;
int n, m;
void solve() {
    memset(temp, 0, sizeof(temp));

    cin >> n >> m;
    cin >> s;

    for(int i=0; i<m; ++i)
        temp[s[i]-'a']+=m-i;
    for(int i=0;i <n; ++i)
        ++temp[s[i]-'a'];
    cout << 



}
int main() {

    while(t--) solve();
    return 0;
}

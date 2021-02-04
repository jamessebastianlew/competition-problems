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

const int mxN =1e2+1;
bool vis[mxN];
int main() {
    cio();
    int n, x;
    int a;
    cin >> x >> n;
    for(int i=0; i<n; ++i)
        cin >> a, vis[a] = true;

    int mn = 0x3f3f3f3f;
    for(int i=0; i<=101; ++i)
        if(i==101 || !vis[i]) if(abs(x-i) < abs(x-mn)) mn = i;

    cout << mn << endl;

    return 0;
}

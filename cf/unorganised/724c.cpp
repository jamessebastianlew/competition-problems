
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
bool seen[4*mxn][2][2]; // 0 is -1, 1 is 1
int n,m,k;
int kk[mxn];
map<int, int> ks;
int main() {
    cin >> n >> m >> k;
    array<int, 2> temp;
    for(int i=0; i<n; ++i) cin >> temp[0] >> temp[1], ks[temp] = i;
    int dx = 1;
    int dy = 1;
    while(!seen[i]) {
        

    }

    return 0;
}

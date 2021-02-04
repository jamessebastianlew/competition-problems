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

const int mxn = 101;
int n;
char aa[mxn][mxn];
int cols[mxn];
int rows[mxn];


int main() {
    cin >> n;
    memset(cols, 0, sizeof(cols));
    memset(rows, 0, sizeof(rows));
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
        cin >> aa[i][j];

    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
        if(aa[i][j] == 'D') ++rows[i], ++cols[j];

    int mx = 0;
    for(int i=0; i<n; ++i) for(int ht=1; ht<=n; ++ht) {
        bool prf = true;
        for(int j=0; j<ht; ++j) if(j >=n || rows[i+j] < ht) { prf = false; break; }
        if(prf && ht > mx) mx = ht;

        prf = true;
        for(int j=0; j<ht; ++j) if(j>=n || cols[i+j] < ht) { prf = false; break; }
        if(prf && ht > mx) mx = ht;
    }
    cout << mx << endl;
    return 0;
}

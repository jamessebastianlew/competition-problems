
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

int n, m;
const int mxn = 101;
const int mxm = 101;
int s[mxm], c[mxm];
array<int, 2> d[mxm];

int aa[mxn];
int main() {
    cio();
    cin >> n >> m;
    
    for(int i=0; i<m; ++i) cin >> s[i] >> d[i][0] >> c[i], d[i][1] = i;
    
    
    sort(d, d+m);
    
    // scratch that
    //
    // do the exams in order

    for(int i=0; i<m; ++i) aa[d[i][0]] = m+1;

    for(int i=0; i<m; ++i) {
        for(int j=s[d[i][1]]; j<d[i][0]; ++j) 
            if(aa[j]==0 && c[d[i][1]]) aa[j] = d[i][1]+1, --c[d[i][1]];
            else if(c[d[i][1]]==0) break;
        if(c[d[i][1]] > 0) { cout << -1 << endl; return 0; }
    }

    for(int i=1; i<=n; ++i) cout << aa[i] << ' ';
    cout << endl;
    return 0;
}


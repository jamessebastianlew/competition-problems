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

int n;
const int mxn = 1e6+5;
const int width = 1414;
const int mxb = 1001;

array<int, 3> aa[mxn];
vector<array<int, 3>> blk[mxb];

int dd(array<int, 3> a, array<int, 3> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

int main() {
    cio();

    cin >> n;
    for(int i=0; i<n; ++i) cin >> aa[i][0] >> aa[i][1], aa[i][2] = i+1;
    sort(aa, aa+n, [&](auto a, auto b) { return a[0]<b[0]; });

    for(int lo=0, hi=width, cntr=0; lo<mxn; lo+=width, hi+=width, ++cntr)
    for(int i=0; i<n; ++i)
        if(aa[i][0] >= lo && aa[i][0] < hi)
            blk[cntr].push_back(aa[i]); 

    for(int i=0; i<mxb; ++i){
        if((int)blk[i].size()==0) continue;
        sort(blk[i].begin(), blk[i].end(), [&](auto a, auto b)
            { return a[1]<b[1]; });
        for(auto v : blk[i]) cout << v[2] << ' ';
    }
    cout << endl;

    return 0;
}


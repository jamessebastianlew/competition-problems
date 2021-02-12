
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

const int mxn = 105;
bool temp[mxn];
array<int,2> aa[mxn];
int main() {

    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        int l,r;
        cin >> l >> r;
        for(int j=l; j<=r; ++j) temp[j] = true;

    }

    vector<int> tmp;
    for(int i=1; i<=m; ++i) 
        if(!temp[i])
            tmp.push_back(i);

    cout << tmp.size() << endl;
    for(int i=0; i<(int)tmp.size(); ++i)
        cout << tmp[i] << ' ';
    cout << endl;


    return 0;
}


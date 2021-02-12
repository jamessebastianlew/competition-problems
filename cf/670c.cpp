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

const int mxn = 2e5+5;
int n, m;

unordered_map<int, int> nm_lang;

int bb[mxn];
int cc[mxn];

int main() {
    cin >> n;
    int a;
    for(int i=0; i<n; ++i) cin >> a, ++nm_lang[a];

    cin >> m;
    int mx = 0;
    int mx_ind = 0;
    int a,b;
    for(int i=0; i<m; ++i) {
        cin >> a >> b;
        if(
        

    return 0;
}

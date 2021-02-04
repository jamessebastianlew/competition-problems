
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

set<int> sl;
string s;
int n, k;
int cnt[26];
int main() {

    cin >> n >> k;
    cin >> s;
    char mx = 'a';
    for(int i=0; i<n; ++i) amax(mx,s[i]), sl.insert(s[i]);
    for(int i=0; i<k; ++i) 
    return 0;
}

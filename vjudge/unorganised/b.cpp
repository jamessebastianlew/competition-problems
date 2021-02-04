
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

string s;
int main() {
    cio();
    cin >> s;
    int cnt = 0;
    const int n = s.size();
    for(int i=0; i<n; ++i) 
        if(s[i] == 'a')
            ++cnt;

    int non = n-cnt;

    int temp = max(non-(cnt-1), 0);
    cout << (n-temp);

    return 0;
}

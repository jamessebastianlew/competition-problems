
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

long long a, b;
int main() {
    cio();
    cin >> a >> b;
    for(int i=0; i<1000; ++i) {
        if(a > b) { cout << i; return 0; }
        a*=3; b*=2;
    }

    return 0;
}

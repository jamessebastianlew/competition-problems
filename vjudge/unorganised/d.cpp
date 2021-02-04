
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

int n;
int a,b,c,d;
int main() {
    cin >> a >> b >> c >> d;

    int total = 0;
    int temp;
    // a c d
    temp = min({a,c,d});
    total += temp*256;
    
    a -= temp;
    c -= temp;
    d -= temp;

    // b a
    temp = min({b,a});
    total += temp*32;

    cout << total;

    return 0;
}

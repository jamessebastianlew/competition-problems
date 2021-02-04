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

int a,b,x;
int main() {
    cio();
    cin >> a >> b;
    int ok = true;
    if(b&1) ok = false;
    else {
        int mx = b/2;
        int mn = (b+3)/4;
        if(!(a<=mx && a>=mn)) ok = false;
    }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}


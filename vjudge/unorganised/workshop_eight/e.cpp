
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

int n,w;
int main() {
    cio();
    cin >> n >> w;
    int curr = 0;
    int mn = 0x3f3f3f3f;
    int mx = 0;
    int temp;
    for(int i=0; i<n; ++i)
        cin >> temp, curr+=temp, amin(mn, curr), amax(mx, curr);
    int least = max(0, -mn);
    int most = w-max(mx,0);
    cout << max(most-least+1, 0) << endl;



    

    return 0;
}

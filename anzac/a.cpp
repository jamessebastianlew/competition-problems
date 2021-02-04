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

const int mxn = 1001;
int n;
map<int, int> freq;
int aa[mxn];
int main() {
    cin >> n;

    int mx = 0;
    int temp;

    for(int i=0; i<n; ++i)
        cin >> aa[i], temp=aa[i], ++freq[temp], amax(mx, freq[temp]);
    int best = INT_MAX;
    for(int i=0; i<n; ++i) 
        if(freq[aa[i]] == mx && aa[i] < best) best = aa[i];

    cout << best << endl;

    return 0;
}

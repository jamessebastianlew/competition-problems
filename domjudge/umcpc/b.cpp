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
void amod(T& a, T b) { a=a>=b?a-b:a; }

using namespace std;

const int mxn = 1e5+5;

int aa[mxn];
int bb[mxn];

int n;

int main() {
    cio();
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> aa[i] >> bb[i];

    sort(aa, aa+n);
    sort(bb, bb+n);
    
    int j=0;
    int cnt= 0;
    for(int i=0; i<n; ++i) {
        // lowest i person gets lowest possible toilet paper
        while(j<n && bb[j] < aa[i]) ++j;
        if(j>=n) break;
        ++cnt, ++j;
    }

    cout << cnt << endl;

        
        


    return 0;
}

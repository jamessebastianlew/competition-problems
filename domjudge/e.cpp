
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
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

int n, d;
int cc[51];
int bb[51];

int main() {
    cio();
    int bec, cs;
    cin >> n >> d;
    cin >> bec >> cs;
    // all numbers after bec will be bec-1
    for(int i=1; i<=n; ++i) bb[i] = i;
    for(int i=1; i<=n; ++i) cc[i] = n-i+1;
    if(bec!=0) {
        for(int i=bec; i<n; ++i) 
            bb[i] = i+1;
    }
    if(cs!=0) {
        for(int i=cs; i<n; ++i) 
            cc[i] = cc[i]-1;
    }


    int a, b;
    for(int i=1; i<=d; ++i) {
        cin >> a >> b;
        if(bb[a] == cc[b])
            cout << "Day " << i << " ALERT" << endl;
        else
            cout << "Day " << i << " OK" << endl;
    }
        
    return 0;
}

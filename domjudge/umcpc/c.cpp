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

int n, t;
string s;
vector<int> order;
vector<int> orderz;
void solve() {
    cin >> n >> s;
    for(int i=0; i<(n>>1); ++i) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    int cnt_bad = 0;

    for(int i=0; i<n; ++i) if(s[i]=='1') ++cnt_bad;
    if(cnt_bad > (n+1)/2) { cout << -1 << endl; return; }

    int tot = 0;
    int ones = 0;
    for(int i=0; i<n; ++i) {
        // need 0
        int found = i;
        if(ones == cnt_bad) break;
        if(i&1) {
            for(int j=i; j<n; ++j)
                if(s[j]=='0') { found = j; break; }
            if(found==i)
                continue;
            for(int j=found; j>i; --j)
                swap(s[j], s[j-1]), ++tot;
        } else {
            ++ones;
            for(int j=i; j<n; ++j)
                if(s[j]=='1') { found = j; break; }
            if(found==i)
                continue;
            for(int j=found; j>i; --j)
                swap(s[j], s[j-1]), ++tot;
        }
    }
    
    cout << tot << endl;
    
}
int main() {
    cio();
    cin >> t;
    while(t--) solve();

    return 0;
}

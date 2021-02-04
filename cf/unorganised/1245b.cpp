
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int t;
int a, b, c;
int A, B, C;
string s;
void solve() {
    cin >> n >> a >> b >> c;
    cin >> s;

    A=B=C=0;

    for(char x : s) {
        if(x == 'R') ++A;
        else if(x=='P') ++B;
        else if(x=='S') ++C;
    }

    int temp_a = min(A,b);
    int temp_b = min(B,c);
    int temp_c = min(C,a);

    if((temp_a+temp_b+temp_c)<(n+1)/2) {
        cout << "NO" << endl;
        return;
    }

    string ans(n, '?');
    for(int i=0; i<n; ++i){
        if(s[i]=='R') {
            if(temp_a>0)
                --temp_a, --b, ans[i]='P';
            continue;
        }
        if(s[i]=='P') {
            if(temp_b>0)
                --temp_b, --c, ans[i]='S';
            continue;
        }
        if(s[i]=='S') {
            if(temp_c>0)
                --temp_c, --a, ans[i]='R';
            continue;
        }
    }
    for(int i=0; i<n; ++i) {
        if(ans[i]=='?') {
            if(a>0)
                ans[i]='R', --a;
            else if(b>0)
                ans[i]='P', --b;
            else
                ans[i]='S', --c;
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--) {
        solve();
    }
    


    return 0;

}


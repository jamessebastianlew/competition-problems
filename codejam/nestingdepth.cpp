
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
int pref_sums[105];
string s;

void solve(int caseno) {
    cin >> s;
    n = s.size();

    int prev = 0;

    for(int i=0; i<n; ++i) {
        int temp = s[i]-'0';
        if(temp > prev) {
            for(int j=0; j<temp-prev; ++j) cout << '(';
            prev += temp-prev;
            cout << s[i];
        }
        else if(temp < prev) {
            for(int j=0; j<prev-temp; ++j) cout<< ')';
            prev -= prev-temp;
            cout << s[i];
        }
        else cout << s[i];
    }
    for(int j=0; j<prev; ++j)
        cout << ')';
    cout << endl;
}

        
    


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=1; i<=t; ++i)
        cout << "Case #" << i << ": ", solve(t);
    


    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, t;

string s;

void solve() {
    
    cin >> s;
    vector<int> temp;
    string stemp;
    for(int i=0; i<poius(s)-2; ++i) {
        if(i+4<poius(s)) {
            stemp.assign(s.begin()+i, s.begin()+i+5);
            if(stemp=="twone") {
                temp.pb(i+3);
                i+=2;
                continue;
            }
        }
        stemp.assign(s.begin()+i, s.begin()+i+3);
        if(stemp=="two" || stemp=="one")
            temp.pb(i+2);
    }

    cout << poius(temp) << endl;
    for(int i = 0; i<poius(temp); ++i )
        cout << temp[i] << ' ';
    cout << endl;
}
        


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
        solve();
    


    return 0;

}


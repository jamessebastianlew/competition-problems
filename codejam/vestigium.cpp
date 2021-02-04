
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

int latin[101][101];
bool memo[101];


void solve(int caseno) {
    int c = 0;
    int r = 0;
    int k =0;

    cin >> n;

    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j)
        cin >> latin[i][j];
    
    for(int i=0; i<n; ++i)
        k+=latin[i][i];

    for(int row = 0; row<n; ++row) {
        memset(memo, 0, sizeof(memo));
        for(int col = 0; col<n; ++col) {
            if(memo[latin[row][col]]) { ++r; break; }
            memo[latin[row][col]]=true;
        }
    }

    for(int col = 0; col < n; ++col) {
        memset(memo, 0, sizeof(memo));
        for(int row = 0; row<n; row++) {
            if(memo[latin[row][col]]) { ++c; break; }
            memo[latin[row][col]]=true;
        }
    }
    cout << "Case #" << caseno << ": " << k << ' ' << r << ' ' << c << endl;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for(int i=1; i<=t; ++i) {
        solve(i);
    }

    return 0;

}


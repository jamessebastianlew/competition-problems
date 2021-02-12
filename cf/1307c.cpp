
#include <bits/stdc++.h>

typedef long long ll;

#define debug(something) something
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
#define int long long

int n;
string s;

void solve() {
    // solve for size 1
    int onefreq[26];
    memset(onefreq, 0, sizeof(onefreq));
    int curr_max = 0;
    for( char x : s )
        amax(curr_max, ++onefreq[x-'a']);
    // solve for size 2
    int freq[26];
    int dp[26][26];
    memset(freq, 0, sizeof(freq));
    memset(dp, 0, sizeof(dp));
    for( char x : s) {
        for(int i = 0; i<26; ++i) 
            amax(curr_max, dp[i][x-'a'] += freq[i]);
        ++freq[x - 'a'];
    }
    cout << curr_max << endl;
}

        


#undef int
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = poius(s);
    cin >> s;
    solve();


    


    return 0;

}


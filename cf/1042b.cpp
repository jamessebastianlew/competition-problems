
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define szz(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
string s;

int dp[0b111+1];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cost;
    // the dp relation is dp[0bxyz] = min itself and dp[0babc|0bdef] + cost
    // such that 0babc | 0bdef == 0bxyz

    memset(dp, 0x3f, sizeof(dp));

    cin >> n;
    
    dp[0]=0;
    while(n--) {
        cin >> cost >> s;
        
        int temp = 0;
        for(char x : s)
            temp |= (1<<(x-'A'));

        for(int i=0; i<8; ++i)
            amin(dp[i|temp], dp[i]+cost);
    }

    cout << (dp[0b111]>300000?-1:dp[0b111]) << endl;

    return 0;

}


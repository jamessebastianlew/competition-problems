
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
int a, b, c;
/*
int dp[4001];
bool seen[4001];
*/

bitset<4001> wow;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*

    vector<int> options(3);
    cin >> n;
    for(int i=0; i<3; ++i)
        cin >> options[i];

    seen[0] = true;
    for(int i = 0; i<=n; ++i)
        for(int x : options)
            if(i+x<=n && seen[i]) amax(dp[i+x], dp[i]+1), seen[i+x]=true;

    cout << dp[n] << endl;
    */

    cin >> n >> a >> b >> c;

    int ans = 0;

    wow[0] = 1;
    for(int i=1; i<=n; ++i)
        if( (wow = ((wow << a) | (wow << b) | (wow << c)))[n] )
            ans = i;

    cout << ans << endl;




    


    return 0;

}


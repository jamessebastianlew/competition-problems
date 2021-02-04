#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 1000000007

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

const int MAX_N = 2005;

using namespace std;

int n, m;

int s[MAX_N];
int t[MAX_N];

int pref[MAX_N][MAX_N]; 

//  if S[i]==T[j]
//      pref[i][j]=pref[i-1][j]+pref[i][j-1]
//  else
//      pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]

int main() {
    
    cin >> n >> m;
    
    pref[0][0]=1;

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        pref[i][0]=1;
    }
    for(int j = 1; j <= m; j++) {
        cin >> t[j];
        pref[0][j]=1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i]==t[j])
                pref[i][j]=(pref[i-1][j]+pref[i][j-1])%MOD;
            else
                pref[i][j]=(pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1])%MOD;
        }
    }

    cout << pref[n][m] << endl;

    return 0;
}
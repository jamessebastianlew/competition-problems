#include <bits/stdc++.h>

using namespace std;

string s;
int q;

const int mxN = 5e3+5;
bool isp[mxN][mxN];
int dp[mxN][mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    const int n = s.size();

    for(int L=n-1; L>=0; --L) for(int R=L+1; R<=n; ++R)
        if(R-L==1) isp[L][R] = true;
        else if(R-L==2 && s[L]==s[R-1]) isp[L][R] = true;
        else if(isp[L+1][R-1] && s[L]==s[R-1]) isp[L][R] = true;


    for(int L=n-1; L>=0; --L) for(int R=L+1; R<=n; ++R)
        dp[L][R] = dp[L+1][R]+dp[L][R-1]-dp[L+1][R-1]+isp[L][R];

    cin >> q;
    int a,b;
    while(q--) {
        cin >> a >> b;
        cout << dp[a-1][b] << '\n';
    }

    return 0;
}

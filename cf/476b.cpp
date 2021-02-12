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

int n, m;

string s1;
string s2;

double dp[11];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;
    n = szz(s1);
    m = szz(s2);
    int np, nm, mp, mm, mq;
    np = nm = mp = mm = mq =  0;
    for(int i = 0; i < n; ++i)
        np += (int)(s1[i]=='+'), nm += (int)(s1[i]=='-');
    for(int i = 0; i < m; ++i) 
        mp += (int)(s2[i]=='+'), mm += (int)(s2[i]=='-'), mq += (int)(s2[i]=='?');

    dp[0]=1;
    for(int i = 1; i<=mq; ++i) {
        for(int j = i; j >= 0; --j)
            dp[j] = (j==0?0:dp[j-1]*0.5) + dp[j]*0.5;
    }

    int need_pos = max(np-mp,0) + max(mm-nm,0);
    int need_neg = max(nm-mm,0) + max(mp-np,0);

    if(need_pos + need_neg > mq) {
        printf("%.12lf\n", (double)0.0);
        return 0;
    }
    printf("%.12lf\n", dp[need_pos]);
    

    return 0;

}


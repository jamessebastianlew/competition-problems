
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

string first, second;

int dp[3001][3001];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> first >> second;
    
    for(int i=1; i<=first.size(); ++i)
        for(int j=1; j<=second.size(); ++j)
            dp[i][j]=max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(int)(first[i-1]==second[j-1])});
    
    int temp_i = first.size();
    int temp_j = second.size();
    vector<char> ans;
    while(temp_i>0 && temp_j>0) {
        if(dp[temp_i-1][temp_j-1]!=dp[temp_i][temp_j])
            temp_j--, temp_i--, ans.pb(temp_j);
        else
            temp_j--;
    }

    for(int i=ans.size()-1; i>=0; --i)
        cout << second[ans[i]];
    cout << endl;

        

    return 0;

}


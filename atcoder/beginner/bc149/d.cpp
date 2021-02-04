#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

const int MAX_N = 2e5+5;

int n, k;
int r, s, p;
string t;

vector<char> moves = {'r','s','p'};

bool visited[MAX_N][3];
int dp[MAX_N][3]; // dp[i][j] max score at round [i] with move [j]

unordered_map<char, pair<int, int>> mp;

int best(char temp_move, int round, int score) {
    int move = mp[temp_move].first;
    if(visited[round][move])
        return dp[round][move];

    for(char x : moves) {
        if( x == temp_move )
        
    }
    
    

}

int ans;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> r >> s >> p;
    cin >> t;

    for(int i = 0; i < 3; i++) {
        mp[moves[i]].first=i;
        mp[moves[i]].second=r;
    }
    for(char x : moves)
        best(x, 1, 0);

    return 0;
}

// dp[i+1][j] = max(dp[i+1][j], dp[i][move] + value[j]) if j != move
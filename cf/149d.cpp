#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxn = 701;
ll dp[mxn][mxn][3][3]; // black 0 red 1 blue 2
int stk[mxn];
int mlen = 0;
array<int, 2> matchings[mxn]; // {left, right}

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    const int n = s.size();

    int len = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == '(') stk[len++] = i;
        else matchings[mlen++] = {stk[len--], i};
    }

    // for dfs
    for(int i=0; i<(mlen >> 1); ++i) swap(matchings[i], matchings[mlen-1-i]);

    for(int i=0; i < mlen; ++i) {
        auto& match = matchings[i];
    }

    return 0;
}

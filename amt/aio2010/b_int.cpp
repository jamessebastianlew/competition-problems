#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, h;
int temp_one, temp_two;
int total;

const int MAX_N = 1e5+5;
int dp[MAX_N];
int curr[MAX_N];
bool seen[MAX_N];

int main() {

#ifndef FLOSH
    freopen("dancein.txt","r",stdin);
    freopen("danceout.txt","w",stdout);
#endif

    cin >> n >> h;

    vector<int> dancers;
    dancers.reserve(MAX_N);

    rep(i, 0, h) {
        cin >> temp_one >> temp_two;

        if(!seen[temp_one])
            dancers.pb(temp_one), seen[temp_one]=true;

        curr[temp_two]++;
        curr[temp_one]--;

        min_self(dp[temp_one],curr[temp_one]);
    }

    for(int x : dancers)
        total-=dp[x];
    cout << total << endl;

    return 0;
}
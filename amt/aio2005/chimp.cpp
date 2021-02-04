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

int n;


// x,y
pair<int, int> dir = {1,0};

void turnleft() {
    dir = {-dir.second, dir.first};
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("dancein.txt","r",stdin);
    freopen("danceout.txt","w",stdout);
#endif

    pair<int, int> curr_pos = {0,0};
    
    pair<int, int> temp_pos;
    cin >> temp_pos.first >> temp_pos.second;
    
    int cnt = 0;

    while(temp_pos.first!=curr_pos.first && temp_pos.second!=curr_pos.second) {
        curr_pos.first+=dir.first;
        curr_pos.second+=dir.second;
        cnt++;
        turnleft();
    }

    cout << cnt << endl;

    return 0;

}

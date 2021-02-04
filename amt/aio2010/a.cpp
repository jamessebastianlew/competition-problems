#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, h;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("snapin.txt","r",stdin);
    freopen("snapout.txt","w",stdout);

    cin >> n >> h;

    int max_count = 0;
    int temp_count = 0;
    int temp;
    rep(i, 0, n) {
        cin >> temp;
        if(temp >= h)
            temp_count++;
        else
            temp_count = 0;    
        max_self(max_count, temp_count);
    }

    cout << max_count;
    return 0;

}
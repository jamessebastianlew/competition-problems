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
char tempb[100];
int ans = 0;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        bool found = false;
        cin >> n >> tempb;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(tempb[i]=='A')
                found = true;
            if(found)
                cnt = tempb[i]=='P'?0:cnt+1, max_self(ans, cnt);
        }
        cout << ans << '\n';
        ans = 0;
    }

    return 0;

}

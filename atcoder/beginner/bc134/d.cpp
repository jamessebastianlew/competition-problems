#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, k;
const int MAX_N = 2e5+5;

bool curr[MAX_N];
bool a[MAX_N];
int temp;

int cnt;

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        a[i]=temp%2;
    }

    for(int i = n; i > 0; i--) {
        cnt = 0;
        int b = i;
        while(b <= n) {
            cnt+=curr[b];
            b+=i;
        }
        curr[i]=(cnt+(int)a[i])%2;
    }
    vector<int> yo;
    yo.reserve(MAX_N);

    cnt = 0;
    for(int i = 1; i <= n; i++){
        if(curr[i])
            cnt++, yo.push_back(i);
    }
    cout << cnt << endl;
    for( auto x : yo )
        cout << x << endl;

    return 0;

}

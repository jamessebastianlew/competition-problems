#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, h;
int temp;


FILE* input;
FILE* output;

int dp[100005];

int main() {

    input = freopen("snapin.txt","r",stdin);
    output = freopen("snapout.txt","w",stdout);

    cin >> n >> h;
    
    cout << pairs << endl;

    return 0;
}
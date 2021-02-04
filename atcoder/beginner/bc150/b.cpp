#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n;
string s;
string temp = "ABC";
string curr;
int cnt;

int main() {

    cin >> n;
    cin >> s;

    for(int i = 0; i < n-2; i++) {
        curr.assign(s, i, 3);
        if(curr==temp)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}
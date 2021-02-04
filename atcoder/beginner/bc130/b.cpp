#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int temp;
ll curr;
bool found;
int n, x;

int i = 0;

int main() {

    cin >> n >> x;

    for(i = 2; i < n+2; i++) {
        cin >> temp;
        curr+=temp;
        if(curr > x) {
            found = true;
            cout << i-1;
            break;
        }
    }

    if(!found)
        cout << (n+1);
    cout << endl;

    return 0;
}
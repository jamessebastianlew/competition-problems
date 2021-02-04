#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, k;
double temp;
double curr_max=0;
double pref[1000000];

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        pref[i]=pref[i-1]+(temp+1.0)/2.0;
    }

    for(int i = 0; i+k <= n; i++) { 
        if(pref[i+k]-pref[i]>curr_max)
            curr_max = pref[i+k]-pref[i];
    }

    cout << curr_max << endl;

    return 0;
}
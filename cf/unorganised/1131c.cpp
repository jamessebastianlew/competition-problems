
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int a[101];
int b[101];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];

    sort(a, a+n);
    int lo=0, hi=n-1;
    while(lo<=hi) {
        b[lo]=a[lo*2];
        if(lo!=hi) b[hi]=a[lo*2+1];
        ++lo, --hi;
    }

    for(int i=0; i<n; ++i) cout << b[i] << ' ';

    
    
    


    return 0;

}


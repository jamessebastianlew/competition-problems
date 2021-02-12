
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
long long n, k;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    
    // the middle of the entire array will always be n
    
    long long lo=1, hi=1;
    for(int i=0; i<n; ++i) hi*=2;
    hi-=1;
    long long midval = n;
    while(lo<=hi) {
        long long mid = (lo+hi+1)>>1;
        if(k>mid) lo = mid+1, --midval;
        else if(k<mid) hi = mid-1, --midval;
        else break;
    }

    cout << midval << endl;

    return 0;

}


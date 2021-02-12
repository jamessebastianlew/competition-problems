
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
#define int long long
template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long

int n;
int k;

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int lo=-1, hi=n+1;
    while(lo+1<hi) {
        int mid = (lo+hi)>>1;
        if((mid*mid+3*mid)/2<=n+k) lo = mid;
        else hi = mid;
    }
    cout << (n-lo) << endl;


    return 0;

}


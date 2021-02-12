
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
#define int long long
int n;

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int loroot = -1, hiroot = n+1;
    while(loroot + 1 < hiroot) {
        int mid = (loroot + hiroot) >> 1;
        if(mid*mid >= n) hiroot=mid;
        else loroot=mid;
    }
    
    int temp = hiroot;
    int lo=-1, hi=n+1;
    while( lo+1 < hi ) {
        int mid = (lo+hi)>>1;
        if(temp*mid>=n) hi=mid;
        else lo = mid;
    }
    cout << temp + hi << endl; 


    return 0;

}



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
int k;
int t;

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        int lo = -1, hi = n+1;
        while(lo+1<hi) {
            int mid = (lo+hi)>>1;
            if(mid*(mid-1)/2 +1 <= k) lo = mid;
            else hi = mid;
        }

        for(int i=n-1; i>=0; --i)
            cout << (i==lo||i==k-(lo*(lo-1)/2+1)?'b':'a');
        cout << endl;
    }

    return 0;

}


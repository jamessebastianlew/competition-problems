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

int original[200005];
int pref_sums_right[200005];
int pref_sums_left[200005];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> original[i], pref_sums_left[i]=original[i]+pref_sums_left[i-1];

    for(int i=n; i>=1; --i)
        pref_sums_right[i]=pref_sums_right[i+1]+original[i];

    int curr_max = 0;
    for(int i=1; i<=n; ++i) {
        int lo = i, hi = n+1;
        while(lo+1<hi) {
            int mid = (lo+hi)>>1;
            if(pref_sums_right[mid] <= pref_sums_left[i]) hi = mid;
            else lo = mid;
        }
        if(pref_sums_right[hi]==pref_sums_left[i])
            max_self(curr_max, pref_sums_left[i]);
    }
    cout << curr_max << endl;

    return 0;

} 

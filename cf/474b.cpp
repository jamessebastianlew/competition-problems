
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


int n, m;
int temp;
int pref_sums[100005];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; ++i) 
        cin >> pref_sums[i], pref_sums[i]+=pref_sums[i-1];

    cin >> m;
    int lo = 0, hi=n+1;
    int mid;
    while(m--) {
        cin >> temp;
        lo=0, hi=n+1;
        while(lo+1<hi) {
            mid = (lo+hi)>>1;
            if(temp<=pref_sums[mid]) hi=mid;
            else lo = mid;
        }
        cout << hi << endl;
    }

    


    return 0;

}


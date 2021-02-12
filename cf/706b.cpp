
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
int temps[100005];
int lo, hi, temp;
int q;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    poiu(n) cin >> temps[i];

    sort(temps, temps+n);
    cin >> q;

    while(q--) {
        cin >> temp;
        lo=-1, hi=n;
        while(lo+1<hi) {
            int mid = (lo+hi)/2;
            if(temps[mid]<=temp) lo=mid;
            else hi=mid;
        }
        cout << lo+1 << endl;
    }

    return 0;

}


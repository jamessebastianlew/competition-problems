
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

ll n;
ll d, a;
ll j;
ll pref_arr[200005];

array<int, 2> monster[200005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans=0;

    cin >> n >> d >> a;

    for(int i=0; i<n; i++) cin >> monster[i][0] >> monster[i][1];

    sort(monster, monster+n);

    for(int i=0; i<n; i++) {
        j=n;
        for(int x=n; x>0; x>>=1)
            while(j-x>=0 && monster[j-x][0]>monster[i][0]+2*d) j-=x;
        ll need = max((monster[i][1]-pref_arr[i]*a+a-1)/a, 0ll);
        ans+=need;
        pref_arr[i]+=need;
        pref_arr[j]-=need;
        pref_arr[i+1]+=pref_arr[i];
    }

    cout << ans << endl;




    


    return 0;

}


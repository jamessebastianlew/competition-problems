
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
int s;

int x, y, temp;
array<int, 2> ks[1001];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i=0; i<n; ++i) {
        cin >> x >> y >> temp;
        ks[i][0]=x*x+y*y;
        ks[i][1]=temp;
    }

    int lo = -1, hi = 0x3f3f3f3f3f3f3f;
    int mid, total;

    while(lo+1<hi) {
        mid = (lo+hi)>>1;
        total=s;
        for(int i=0; i<n; ++i)
            total+=(ks[i][0]<=mid)?ks[i][1]:0;
        if(total>=1000000) hi = mid;
        else lo = mid;
    }

    if(hi!=0x3f3f3f3f3f3f3f)
        printf("%.7lf\n", sqrt(hi));
    else
        cout << -1 << endl;
        
        
    


    return 0;

}


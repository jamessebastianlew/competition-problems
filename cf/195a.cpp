
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

int a,b,c;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    
    int lo=-1, hi=1001;
    while(lo+1<hi) {
        int mid = (lo+hi)>>1;
        if(mid*b+b*(c-mid-1)>=a*c) hi = mid;
        else lo = mid;
    }
    cout << hi << endl;
    


    return 0;

}


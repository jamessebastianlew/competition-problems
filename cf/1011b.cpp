
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
int m;
int a[1000];
int temp;

int amounts[1000];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> unique;
    unique.reserve(100);

    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> temp;
        if(amounts[temp]==0)
            unique.pb(temp);
        ++amounts[temp];
    }
    int lo=0, hi=m+1;
    int mid;
    while(lo+1 < hi) {
        temp = 0;
        mid = (lo+hi)>>1;
        for(int i=0; i<unique.size(); ++i)
            temp+=amounts[unique[i]]/mid;
        if(temp>=n) lo=mid;
        else hi=mid;
    }
    cout << lo << endl;

    return 0;

}


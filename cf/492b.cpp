
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
int l;

int a[1005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for(int i=0; i<n; ++i) cin >> a[i];
    
    sort(a,a+n);
    int max_gap=0;
    int temp = 0;
    for(int i=1; i<n; ++i)
        temp = a[i]-a[i-1], max_self(max_gap, temp);

    double ans = max({(double)max_gap/2, (double)a[0], (double)(l-a[n-1])});
    printf("%.10lf\n", ans);


    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long


int n, q;

int a[100005];
int sorted_a[100005];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i<=n; ++i)
        cin >> a[i], sorted_a[i]=a[i];

    sort(sorted_a+1, sorted_a+n+1);

    for(int i=1; i<=n; ++i)
        a[i]=a[i-1]+a[i], sorted_a[i]=sorted_a[i-1]+sorted_a[i];
    
    cin >> q;
    int type;
    int lo, hi;
    while(q--) {
        cin >> type >> lo >> hi;
        if(type == 1)
            cout << (a[hi]-a[lo-1]) << endl;
        else
            cout << (sorted_a[hi]-sorted_a[lo-1]) << endl;

    }



    return 0;

}


#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, k;

const int MAX_N = 2e5+5;

int st[MAX_N*2];

void build() {
    for(int i = n-1; i > 0; i--)
        st[i]=max(st[i<<1],st[i<<1|1]);
}

int range(int l, int r) {
    int p = 0;

    for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
        if(l&1) max_self(p, st[l++]);
        if(r&1) max_self(p, st[--r]);
    }

    return p;
}



int main() {
    
    cin >> n;
    
    for(int i = n; i < 2*n; i++)
        cin >> st[i];
    
    build();
    
    cout << range(1,n) << endl;

    for(int i = 1; i < n-1; i++) {
        int temp = max(range(0,i),range(i+1,n));
        cout << temp << endl;
    }
    int temp2 = range(0,n-1);
    cout << temp2 << endl;
    return 0;
}

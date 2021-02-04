
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

const int mxX=1000005;
const int mxN=2005;

int st[mxX*2]

void build() {
    for(int i = n-1; i>0; i--)
        st[i]=max(st[i<<1], st[i<<1|1]);
}

int get_max(int l, int r) {
    int curr_max = 0;
    for(l+=n,r+=n; l < r; l>>=1, r>>=1) {
        if(l&1) curr_max = max(curr_max,st[l


pair<int, int> points[2001];
int max_height[2001];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for(int i=0; i<n; i++)

    return 0;

}

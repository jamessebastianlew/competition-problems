
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define gofor(n) for(int i=0; i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int a[200001];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    gofor(n)
        cin >> a[i];

    int curr = 1;
    gofor(n)
        curr=a[i]==curr?curr+1:curr;


    if(curr==1)
        cout << -1 << endl;
    else
        cout << n-curr+1 << endl;

    return 0;

}

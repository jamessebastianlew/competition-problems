
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b;
    cin >> a >> b;
    
    int temp=-1;
    for(int i = 1; i <= 3; i++)
        temp = max(temp,i==a?0:i==b?0:i);

    cout << temp << endl;
    

    return 0;

}

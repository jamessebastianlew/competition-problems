
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
string s,t;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    vector<char> temp(2*n);
    cin >> s >> t;
    for(int i = 0; i<n; i++)
        temp[2*i]=s[i], temp[2*i+1]=t[i];

    for(int i = 0; i<2*n;i++)
        cout << temp[i];
    cout << endl;
    return 0;

}

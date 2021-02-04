
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD (int)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, s;
    cin >> n >> k >> s;

    for(int i=0; i<k; i++) {
        cout << s << ' ';
    }
    if(s==1000000000) {
        for(int i=0; i<n-k;i++) 
            cout << 1 << ' ';
    } else {
        for(int i = 0; i < n-k; i++)
            cout << 1000000000 << ' ';
    }
    cout << endl;
    


    return 0;

}


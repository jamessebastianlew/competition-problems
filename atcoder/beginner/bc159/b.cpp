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
string s;

bool ispal(int lo, int hi) {
    while(lo<hi) {
        if(s[lo]!=s[hi])
            return false;
        hi--,lo++;
    }
    return true;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    const int n = s.size();
    cout << ((ispal(1-1,(n-1)/2-1)&&ispal((n+3)/2-1,n-1)&&ispal(0,n-1))?"Yes":"No") << endl;
    


    return 0;

}


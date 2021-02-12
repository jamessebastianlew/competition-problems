
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


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> n;

    int cnt = 0;
    int max_count = 0;
    while(n--) {
        max_count = 0;
        cnt=0;
        cin >> s;
        for(int i=0; i<s.size(); i++)
            cnt=s[i]=='L'?cnt+1:0, max_self(max_count, cnt);
        cout << max_count+1 << endl;
    }

    return 0;

}


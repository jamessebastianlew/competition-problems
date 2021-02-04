
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

int h, w;
int k;

int pref_arr[11][1001];
char white[11][2001];
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> k;

    for(int i=1; i<=h; i++) for(int j=1; j<=w; j++) {
        cin >> white[i][j];
        pref_arr[i][j]=pref_arr[i-1][j]+pref_arr[i][j-1]-pref_arr[i-1][j-1]+white[i][j]-'0';
    }

    ll cnt=0;
    for(int r1=1; r1<=h; ++r1) for(int c1=1; c1<=w; ++c1)  for(int r2=r1; r2<=h; r2++) for(int c2=c1; c2<=w; c2++) {
        if(pref_arr[r2][c2]-pref_arr[r1-1][c2]-pref_arr[r2][c1-1]+pref_arr[r1-1][c1-1]<=k)
            cnt+=1LL;
    }
    cout << cnt << endl;


    return 0;

}


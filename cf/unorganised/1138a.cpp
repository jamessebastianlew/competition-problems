
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
int temp[100005];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i) cin >> temp[i];
    temp[n]=-1;

    int mx=0;
    int prev_line=0;
    int curr_line=1;
    for(int i=1; i<=n; ++i) {
        if(temp[i]==temp[i-1])
            ++curr_line;
        else
            max_self(mx, min(curr_line, prev_line)), prev_line=curr_line, curr_line=1;
    }
    cout << mx*2 << endl;
    return 0;

}


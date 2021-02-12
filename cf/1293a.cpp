
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

int n, s, k;
int t;
int temp;
int temp_two;
int temp_one;

unordered_set<int> closed;

int INF = 0x3f3f3f3f;

void SOLVE() {
    int curr_min = INF;
    int temp_left=0;
    int temp_right=0;
    for(; s+temp_right<=n && closed.count(temp_right+s); ++temp_right);
    for(; s-temp_left>0 && closed.count(s-temp_left); ++temp_left);
    if(temp_left==s)
        curr_min = temp_right;
    else if(s+temp_right==n+1)
        curr_min = temp_left;
    else
        curr_min = min(temp_left, temp_right);
    cout << curr_min << endl;
}
    
    
    

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while(t--) {
        cin >> n >> s >> k;
        closed.clear();
        for(int i=0; i<k; ++i) cin >> temp, closed.insert(temp);
        SOLVE();
    }
    return 0;

}


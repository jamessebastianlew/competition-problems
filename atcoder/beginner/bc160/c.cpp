
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
int k;

int distances[200005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n;
    for(int i=0; i<n; ++i) cin >> distances[i];
    
    int curr_min = 0x3f3f3f3f;
    for(int i=1; i<n; ++i) {
        min_self(curr_min, k-(distances[i]-distances[i-1]));
    }
    min_self(curr_min, k-(k-distances[n-1]+distances[0]));
    cout << curr_min << endl;



    return 0;

}


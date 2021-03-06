
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

int n, m;
int benches[101];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int curr_max = 0;
    int total=0;
    for(int i=0; i<n; ++i) {
        cin >> benches[i];
        total+=benches[i];
        max_self(curr_max, benches[i]);
    }
    total+=m;
    int temp = max((total+n-1)/n, curr_max);
    cout << temp << ' ' << curr_max+m << endl;
    return 0;

}


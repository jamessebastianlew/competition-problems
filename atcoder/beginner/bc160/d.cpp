
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
int x, y;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;
    
    for(int k=1; k<n; ++k) {
        int temp_one = max(max(y-x-1)-max(y-x, 0)+max(x-k+1,0);
        int temp_two = max(n-(y-x-1)-k, 0);
        cout << (temp_one + temp_two) << endl;
    }
    


    return 0;

}


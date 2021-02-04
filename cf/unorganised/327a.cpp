
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

int a[101];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int total = 0;
    for(int i=0; i<n; ++i) cin >> a[i], total += a[i];

    int curr = 0;
    int mxx = -1;
    for(int i=0; i<n; ++i) {
        int temp = a[i]==0?1:-1;
        curr = max(temp, curr+temp);
        max_self(mxx, curr);
    }
    cout << total + mxx << endl;

    return 0;

}


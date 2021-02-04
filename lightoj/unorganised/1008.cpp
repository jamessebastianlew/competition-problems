
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long

int n;
int t;
pair<int, int> start;

void solve() {
    cin >> n;
    int lo = 0, hi = 1e9;
    while(lo+1<hi) {
        int mid = (lo+hi)>>1;
        if(mid*mid >= n) hi = mid;
        else lo = mid;
    }
    bool is_top = hi & 1;
    int left = hi*hi-n;
    int height = (hi*hi - (hi-1)*(hi-1))/2;
    if(!is_top)
        start = {hi-(left-min(height,left)), 1+min(height, left)};
    else
        start = {1+min(height, left), hi-(left-min(height,left))};
    cout << start.first << ' ' << start.second << endl;
}



#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=1; i<=t; ++i)
        cout << "Case " << i << ": ", solve();
    


    return 0;

}


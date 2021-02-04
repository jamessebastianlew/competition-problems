
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

int n, k;

int a[505];
int prev_extra[505];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int total =0 ;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }

    for(int i = 1; i<n; ++i) {
        prev_extra[i] = max(0,k-(a[i]+a[i-1]+prev_extra[i-1]));
        total+=prev_extra[i];
    }
    
    cout << total << endl;
    for(int i=0; i<n; ++i) 
        cout << (prev_extra[i]+a[i]) << ' ';
    

    cout << endl;

    


    return 0;

}


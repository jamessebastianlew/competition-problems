
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

int a[200005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=1; i<=n; ++i)
        cin >> a[i];

    int curr = 0; 
    int curr_max = 0;

    for(int i = 1; i<=n; ++i) {
        curr = a[i]<=2*a[i-1]?curr+1:1;
        max_self(curr_max, curr);
    }

    cout << curr_max << endl;


    


    return 0;

}


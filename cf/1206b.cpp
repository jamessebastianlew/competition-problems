
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
#define int long long

int n;

int a[100005];
int min_neg[100005];
int min_pos[100005];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cin >> a[0];
    min_neg[0] = abs(a[0]+1);
    min_pos[0] = abs(a[0]-1);

    for(int i=1; i<n; ++i) {
        cin >> a[i];
        min_neg[i]=min(min_neg[i-1] + abs(a[i]-1), min_pos[i-1] + abs(a[i]+1));
        min_pos[i]=min(min_pos[i-1] + abs(a[i]-1), min_neg[i-1] + abs(a[i]+1));
    }
    cout << min_pos[n-1] << endl;

    
    


    return 0;

}


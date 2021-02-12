
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

int n;

int a[100005][2];
int pref_sums[100005];
int left_sums[100005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;
    for(int j=0; j<2; ++j)
        for(int i=1; i<=n; ++i) 
            cin >> a[i][j];

    for(int i=1; i<=n; ++i) {
        pref_sums[i]=pref_sums[i-1]+a[i][0];
        left_sums[i]=left_sums[i-1]+a[i][0]*a[i][1];
    }

    amin(k, n);
    int curr_max = left_sums[n];
    for(int i = 1; i+k-1<=n; ++i)
        amax(curr_max, left_sums[n]-(left_sums[i+k-1]-left_sums[i-1])+(pref_sums[i+k-1]-pref_sums[i-1]));
    cout << curr_max << endl;

        
    


    return 0;

}


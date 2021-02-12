
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
const int INF = 0x3f3f3f3f;
int pref_sums[200005];
int curr_min = INF;
int min_index = 0;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int temp;
    for(int i = 1; i<=n; ++i)
        cin >> temp, pref_sums[i]=pref_sums[i-1]+temp;

    for(int i=k; i<=n; ++i) {
        if(pref_sums[i]-pref_sums[i-k]<curr_min) {
            curr_min = pref_sums[i]-pref_sums[i-k];
            min_index = i-k+1;
        }
    }


    cout << min_index << endl;

    return 0;

}


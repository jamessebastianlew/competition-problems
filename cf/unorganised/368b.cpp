
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

int n, m;
int temp;

int pref_sums[100005];
int a[100005];
bool visited[100005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    for(int i=n; i>0; --i) {
        pref_sums[i] = pref_sums[i+1]+(visited[a[i]]?0:1);
        visited[a[i]]=true;
    }

    while(m--)
        cin >> temp, cout << pref_sums[temp] << endl;
    


    return 0;

}



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

int n, b;

int num_odd[101];
int a[101];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;
    for(int i=1; i<=n; ++i)
        cin >> a[i], num_odd[i]=num_odd[i-1]+(a[i]&1?1:0);

    vector<int> cut_costs;
    int prv = 1;
    for(int i=2; i<n; ++i) {
        if(!((i-prv+1)&1) && num_odd[i]-num_odd[prv-1]==(i-prv+1)/2)
            cut_costs.pb(abs(a[i]-a[i+1]));
    }

    sort(cut_costs.begin(), cut_costs.end());
    int total = 0;
    int lastind = -1;
    while(lastind< (int)cut_costs.size()-1 && total+cut_costs[lastind+1] <= b)
        total+=cut_costs[lastind++ +1];

    cout << (lastind+1) << endl;



    


    return 0;

}


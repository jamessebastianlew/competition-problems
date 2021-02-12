#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long
int n, s;
int t;
int temp;

const int mxN = 1e5+5;

void solve() {
    cin >> n >> s;
    int curr_sum = 0;
    bool found = false;
    pair<int, int> curr_max = {0,0};
    for(int i=1; i<=n; ++i) {
        cin >> temp;
        if(!found) {
            curr_sum+=temp;
            if(curr_sum-max(curr_max.first,temp)>s) {
                found = true;
            } else if (temp > curr_max.first)
                curr_max.first = temp, curr_max.second = i;
        }
    }
    if(!found && curr_sum<=s)
        cout << 0 << endl;
    else cout << curr_max.second << endl;
}
        
        

        

#undef int 
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while(t--) {
        solve();
    }
    return 0;

}



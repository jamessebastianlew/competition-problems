
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

int all[5];
int max_pos = 0;
int all_temp[5];

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> all[1] >> all[2] >> all[3];
        
    int diff_min = 2e18;

    for(int start = 0; start<5; ++start) {
        for(int end = 0; end<5; ++end) {
            for(int i=1; i<4; ++i)
                all_temp[i]=all[i];
            for(int i=start+1; i<4; ++i)
                all_temp[i]++;
            for(int i=end-1; i>0; --i)
                all_temp[i]++;
            int diff = 0;
            int mx = 0;
            for(int i=1; i<4; ++i)
                max_self(mx, all_temp[i]), diff+=all_temp[i];
            min_self(diff_min, 3*mx-diff);
        }
    }
    cout << diff_min << endl;





    


    return 0;

}


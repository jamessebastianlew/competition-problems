
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

bool curr_arr[101];

class Bitstructure {
    bool curr_xor;
    bool curr_reverse;

    Bitstructure() {
        memset(curr_arr, 0, sizeof(curr_arr));
        curr_reverse = false;
        curr_xor = false;
    }

    bool& operator [] (int index) {
        assert(index<b);
        if(curr_reverse)
            return curr_arr[b-index-1]^curr_xor;
        else
            return curr_arr[index]^curr_xor;
    }
}

int n;
int t, b;



int find_action(int L, int R, int curr_xor) {
    if
    
    


void solve() {
    int L = b/2;
    int R = b/2;

    int curr_xor = 0;

    set<int> seen;
    memset(curr_arr, 0, sizeof(curr_arr));

    bool pair_found = false;
    int query_number = 1;
    


    
    
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> b;
    while(t--) {
        solve();
    }
    


    return 0;

}


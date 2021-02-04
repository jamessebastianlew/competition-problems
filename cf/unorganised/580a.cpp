
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


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int prev = 0;
    int curr = 0;
    int curr_max = 0;
    int temp;
    for(int i = 0; i<n; ++i) {
         cin >> temp;
         curr = (temp>=prev?curr+1:1);
         max_self(curr_max, curr);
         prev = temp;
    }
    cout << curr_max << endl;
    


    return 0;

}


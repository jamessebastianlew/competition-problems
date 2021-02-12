
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
int t;

int temp;

void solve() {
    cin >> n;

    int odd=0;
    int even=0;
    int curr_even;
    int prev_odd;
    int curr_odd;
    for(int i=0; i<n; ++i) {
        cin >> temp;
        if(temp%2==0)
            ++even, curr_even=i+1;
        else
            ++odd, prev_odd = curr_odd, curr_odd = i+1;
    }
    if(even>0)
        cout << '1' << endl << curr_even;
    else if(curr_odd>1)
        cout << '2' << endl << curr_odd << ' ' << prev_odd;
    else
        cout << -1;
    cout << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--)
        solve();

    


    return 0;

}


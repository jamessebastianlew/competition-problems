
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

string s;

int pref_sums[101];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    
    n = s.size();
    long long total = 0;
    for(int i=0; i<n; ++i)
        pref_sums[i+1]=pref_sums[i]+(int)(s[i]=='Q');
    for(int i=0; i<n; ++i) {
        if(s[i]=='A')
            total+=pref_sums[i+1]*(pref_sums[n]-pref_sums[i+1]);
    }
    cout << total << endl;


    return 0;

}


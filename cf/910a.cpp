
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
string s;

int pref[1000];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> s;

    int num_moves = 0;
    for(int i=0; i<n; ++i)
        pref[i+1]=s[i]=='0'?pref[i]:i+1;

    for(int pos = 1; pos<n; pos=pref[min(n,pos+k)], ++num_moves) {
        if(pos==pref[min(n,pos+k)]) { cout << -1 << endl; return 0; }
    }
    cout << num_moves << endl;

        
        
            
    


    return 0;

}


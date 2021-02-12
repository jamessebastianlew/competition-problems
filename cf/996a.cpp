
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
    
    int items[5] = {1,5,10,20,100};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    int total=0;
    for(int i=4; i>=0; --i)
        total+=n/items[i], n%=items[i];
    cout << total;
    


    return 0;

}


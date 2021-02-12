
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define szz(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

long long n;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int cnt = 0;
    while(n) {
        int mx = 0;
        for(int x = n; x > 0; x/=10)
            amax(mx, x%10);
        n-=mx;
        ++cnt;
    }
    cout << cnt << endl;

    


    return 0;

}


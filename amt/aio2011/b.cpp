
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int s, k, a, b;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("dancein.txt","r",stdin);
    freopen("danceout.txt","w",stdout);
#endif

    cin >> n >> s >> k;
    while(k--) {
        cin >> a >> b;
        if(a==s)
            s=b;
        else if(a<s&&b>=s)
            --s;
        else if(a>s&&b<=s)
            ++s;
    }

    cout << s << endl;

    

    return 0;

}


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
string s, t;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> t;
    sort(t.begin(), t.end());
    sort(s.begin(), s.end());

    //min flicks
    int min_flicks = 0;
    int j = 0;
    for(int i=0; i<n; ++i, ++j)
        while(j<n && s[i]>t[j]) ++j;

    int max_flicks = 0;
    j = n-1;
    for(int i = n-1; i>=0; --i) {
        while(j>=0 && s[j]>=t[i]) --j;
        if(j>-1) ++max_flicks;
    }


    cout << min_flicks << endl << max_flicks << endl;
        




    


    return 0;

}


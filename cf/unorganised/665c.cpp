
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

string s;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = poius(s);
    s+=".";
    for(int i=1; i<n; ++i)
        if(s[i]==s[i-1]) {
            char j;
            for(j=s[i]; j == s[i-1] || j == s[i+1]; j=((j-'a'+1)%26+'a'));
            s[i++]=j;
        }
    string ans(s.begin(), s.end()-1);
    cout << ans << endl;
            


    


    return 0;

}


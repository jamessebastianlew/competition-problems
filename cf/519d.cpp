#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int a[26];
map<long long, int> pref_count[26];
string s;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<26; ++i) cin >> a[i];
    cin >> s;
    n = poius(s);

    long long cnt = 0;
    long long sm = 0;
    for(int i=0; i<n; ++i) {
        cnt += pref_count[s[i]-'a'][sm];
        sm += a[s[i]-'a'];
        ++pref_count[s[i]-'a'][sm];
    }

    cout << cnt << endl;
    

    return 0;

}


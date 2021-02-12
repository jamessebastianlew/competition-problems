#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
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
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }
template<typename T>
void smp(T&a, T b) {a=(a*b)%MOD;}

using namespace std;

int n;

ll temp_one, temp_two;
string s;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    n = poius(s);
    ll power = 1;

    string test1, test2;
    string ans;
    for(int i=0; i<n; ++i, power=power*27%MOD) {
        temp_one=(temp_one+(s[i]-'a')*power)%MOD;
        temp_two=((temp_two*27)%MOD+(s[n-i-1]-'a'))%MOD;
        cout << temp_one << ' ' << temp_two << endl;

        if(temp_one==temp_two) {
            test1.assign(s, 0, i+1);
            test2.assign(s, n-i-1, i+1);
            if(test1==test2)
                ans.assign(s, 0, i+1);
        }
    }

    cout << ans << endl;

    return 0;

}


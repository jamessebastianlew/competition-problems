
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

    long long cnt = 0;

    for(int i = 0; i < poius(s); ++i)
        if((s[i]-'0')%4==0) {
            if(i-1>-1 && ((s[i-1]-'0')*10 + (s[i]-'0'))%4==0)
                cnt+=i+1;
            else
                ++cnt;
        }
        else if(i-1>-1 && ((s[i-1]-'0')*10 + (s[i]-'0'))%4==0)
            cnt+=i;

    cout << cnt << endl;

            
    

    


    return 0;

}


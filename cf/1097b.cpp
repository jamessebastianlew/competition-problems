
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
int temp;
int curr_max =0;

bitset<360> dp2;
bitset<360> dp1;

int modd(int x) {
    if(x<0)
        return x+360;
    if(x<360)
        return x;
    return x-360;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int total = 0; 
    bool found = false;
    dp1[0]=1;
    while(n--) {
        cin >> temp;
        for(int i=0; i<360; ++i)
            if(dp1[i])
                dp2[modd(i+temp)]=1, dp2[modd(i-temp)]=1;
        dp1 = dp2;
        dp2.reset();
    }

    if(total&1) {
        cout << "NO" << endl;
        return 0;

    }

    cout << (found||dp1[total/2]?"YES":"NO") << endl;


    


    return 0;

}


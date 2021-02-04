
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD (int)10e9+7
#define endl'\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int cards[20][2];

bool genperms(int i, vector<bool>& perms) {
    if(i==n) {
        int curr=0;
        for(int temp=0;temp<n;temp++) {
            if(cards[temp][perms[temp]]>curr)
                curr = cards[temp][perms[temp]];
            else
                return false;
        }
    }
    bool found = false;
    perms.push_back(1);
    found |= genperms(i+1, perms);
    perms.pop_back();
    perms.push_back(0);
    found |= genperms(i+1, perms);
    perms.pop_back();
    return found;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<2;i++) for(int j=0;j<n;j++) cin >> cards[j][i];

    vector<bool> perms;
    perms.reserve(100);
    int ans = genperms(0,perms);
    cout << ans << endl;

    


    return 0;

}


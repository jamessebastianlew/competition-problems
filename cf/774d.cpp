
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int l, r;

int vals[100005][2];

int cnt[100005][2];
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r;
    vector<int> temp[2];

    temp[0].reserve(100005);
    temp[1].reserve(100005);

    for(int i=0; i<2; i++) for(int j=1; j<=n; j++)
        cin >> vals[j][i];

    for(int i=1; i<=n; i++) {
        if(i<l||i>r) {
            if(vals[i][0]!=vals[i][1]) {
                cout << "LIE" << endl;
                return 0;
            }
            continue;
        }
        if(cnt[vals[i][0]][0]++==0)
            temp[0].pb(vals[i][0]);
        if(cnt[vals[i][1]][1]++==0)
            temp[1].pb(vals[i][1]);
    } 

    sort(temp[0].begin(),temp[0].end());
    sort(temp[1].begin(), temp[1].end());

    if(temp[0].size()!=temp[1].size()) {
        cout << "LIE" << endl;
        return 0;
    }
    for(int i=0; i<temp[0].size(); ++i) {
        if(temp[0][i]!=temp[1][i] || cnt[temp[0][i]][0]!=cnt[temp[0][i]][1]) {
            cout << "LIE" << endl;
            return 0;
        }
    }
        
    cout << "TRUTH" << endl;


    


    return 0;

}


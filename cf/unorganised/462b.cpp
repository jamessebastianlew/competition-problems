
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
ll cnt[256];
int k;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    string s;
    cin >> s;
    
    vector<char> temp;
    for(char x : s) {
        if(cnt[x]==0)
            temp.pb(x);
        cnt[x]++;
    }

    sort(temp.begin(), temp.end(), [](char a, char b) {return cnt[a] > cnt[b];});

    ll total=0;
    ll used=0;
    
    for(char x : temp) {
        total+=min(k-used, cnt[x])*min(k-used,cnt[x]);
        used += min(k-used, cnt[x]);
    }

    cout << total << endl;
        


    return 0;

}


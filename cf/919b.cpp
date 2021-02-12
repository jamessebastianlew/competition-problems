
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
int k;

int smd(int temp) {
    int sm=0;
    for(; temp>0; temp/=10)
        sm+=temp%10;
    return sm;
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> k;
    
    int cnt = 0;
    int temp = 1;

    while(cnt < k) {
        if(smd(temp)==10)
            ++cnt;
        ++temp;
    }
    cout << temp-1 << endl;


    return 0;

}


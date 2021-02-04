
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int shelf[100001];
int temp;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> shelf[i];

    int m;
    cin >>m;
   
    int prev_i=0;

    while(m--) {

        cin >> temp;
        for(; prev_i<n;prev_i++) {
            if(temp==shelf[prev_i]) {
                cout << prev_i+1 << endl;
                break;
            }
        }

    }

    

    return 0;

}

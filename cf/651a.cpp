
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

int a, b;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    cout<<max((a+b)-2-(a%3==b%3),0) << endl;
    return 0;

}


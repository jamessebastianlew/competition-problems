
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
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

int temp_one, temp_two;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> temp_one >> temp_two;

    cout << (temp_one*(temp_one-1))/2 + (temp_two*(temp_two-1))/2 << endl;
    


    return 0;

}



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
int temp;

pair<int, int> pear[100005];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> temp, pear[i]={temp, i};

    sort(pear+1, pear+n+1, [](auto a, auto b) {return a.first < b.first;});

    for(int i=1; i<=n; i++)
        cout << pear[i].second << ' ';
    cout << endl;





    


    return 0;

}


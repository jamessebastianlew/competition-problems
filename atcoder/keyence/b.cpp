
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

pair<int, int> endpoints[100000];



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> temp_one >> temp_two;
        endpoints[i].first=(temp_one-temp_two);
        endpoints[i].second=(temp_one+temp_two);
    }
    
    sort(endpoints, endpoints+n, [](pair<int, int> x, pair<int, int> y) {if(x.second==y.second){return x.first<y.first;}return x.second < y.second;});

    pair<int,int> prev = endpoints[0];
    int curr_max=1;
    for(int i = 1; i < n; i++) {
        if(endpoints[i].first>=prev.second)
            curr_max++, prev=endpoints[i];
    }

    cout << curr_max << endl;
        

    
    return 0;

}


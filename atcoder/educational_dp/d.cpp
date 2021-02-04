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

#define int long long

const int mxW = 1e5+5;
int n;
int w;

int temp_value, temp_weight;

int weights[mxW];


#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    while(n--) {
        cin >> temp_weight >> temp_value;
        for(int i=w-temp_weight; i>=0; --i)
            max_self(weights[i+temp_weight],weights[i]+temp_value);
    }
    cout << weights[w] << endl;

    return 0;

}


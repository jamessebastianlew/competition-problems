
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

const int mxN = 100005;
int n;
int w;

int temp_weight, temp_value;

int min_weight[100005]; // the min_weight[i] = minimum weight to achieve value i
// min_weight[val+temp_value] = min(itself, min_weight[val]+temp_weight);

#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    memset(min_weight, 0x3f, sizeof(min_weight));
    min_weight[0]=0;
    min_weight[0]=0;
    while(n--) {
        cin >> temp_weight >> temp_value;
        for(int i=mxN-1-temp_value; i>=0; --i)
            min_self(min_weight[i+temp_value], min_weight[i]+temp_weight);
    }

    int curr_max = 0;
    for(int i=0; i<mxN; ++i)
        if(min_weight[i]<=w&&i>curr_max) curr_max = i;

    cout << curr_max << endl;

    return 0;

}


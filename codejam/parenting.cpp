
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
int t;
int temp_one, temp_two;


void solve() {
    //greedy? 
    cin >> n;

    array<int, 3> ranges[1001];
    int choices[1001];
    memset(choices, 0, sizeof(choices));

    for(int i=0; i<n; ++i)
        cin >> ranges[i][0] >> ranges[i][1], ranges[i][2]=i;
    sort(ranges, ranges+n);

    int c_end = 0;
    int c_start = 0;
    int j_end = 0;
    int j_start = 0;

    for(int i=0; i<n; ++i) {
        if(ranges[i][0]>=c_end)
            choices[ranges[i][2]]=1, c_end = ranges[i][1], c_start = ranges[i][0];
        else if(ranges[i][0]>=j_end)
            choices[ranges[i][2]]=2, j_end = ranges[i][1], j_start = ranges[i][0];
    }

    for(int i=0; i<n; ++i)
        if(choices[i]==0) {cout << "IMPOSSIBLE" << endl; return;}
    for(int i=0; i<n; ++i)
        cout << (choices[i]==1?'C':'J');
    cout << endl;
}
        


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for(int i=1; i<=t; ++i)
        cout << "Case #" << i << ": ", solve(); 
    


    return 0;

}


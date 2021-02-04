
#include <bits/stdc++.h>

typedef long long ll;

#define debug(something) something
#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int k;
int l;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int travel = 1+2*k;
    int left = n%travel;
    int front = min(left, k);

    vector<int> ans;
    ans.reserve((n+travel-1)/travel+1);

    for(int i = min(k-front+1, n); i <= n; i+=travel )
        ans.pb(i);
    cout << ans.size() << endl;

    for(int x : ans)
        cout  << x << ' ';
    cout << endl;


        
        

    


    return 0;

}



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
int d;
int t;

void solve() {
    cin >> d;

    double temp = 0.25*d*d-d;
    if(temp>=0) {
        double b = ((double)d/2) + sqrt(temp);
        double a = d-b;
        printf("Y %.9lf %.9lf\n", b, a);
    } else
        printf("N\n");
}

        


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--) {
        solve();
    }
        

    


    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

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
double pi = 2*acos(0.0);


int main() {
    int t;
    double r;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", i, (4*r*r - pi*r*r));
    }

    return 0;

}


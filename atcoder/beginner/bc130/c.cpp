#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, k;
int x, y;
int num_ways;
double area;
double ans;


int main() {
    cin >> n >> k >> x >> y;
    area = n*(double)k/2.0;

    if(!(n&1)) {
        if(x==n>>1)
            num_ways++;
    }
    if(!(k&1)) {
        if(y==k>>1)
            num_ways++;
    }

    cout << area << ' ';


    if(num_ways>1)
        cout << 1;
    else
        cout << 0;
    
    cout << endl;
    



    
    return 0;
}
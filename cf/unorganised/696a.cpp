
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

map<tuple<int,int>, int> costs;

void mark_roads(int a, int b, int v) {
    int temp_a = sizeof(int)*8-__builtin_clz(a);
    int temp_b = sizeof(int)*8-__builtin_clz(b);

    while(temp_a
int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    int temp;
    int a, b, c;

    rep(i,0,q) {
        cin >> temp;
        if(temp==1) {
            cin >> a >> b >> c;

        } else {
            cin >> a >> b;
            
        }
    }


        
    
	
	return 0;

}


#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int temp_k;
int k;
int cnt;

bool open[100001];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> c >> k;
    
    int temp;
    while(n--) {
        cin >> temp;

        if(!open[temp]) {
            if(temp_k==k)
                cnt++;
            else
                temp_k++;
            cnt++;
            open[temp]=true;
        }

    }
    
    cout << cnt << endl;


        
    return 0;

}

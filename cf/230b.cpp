
#include <bits/stdc++.h>

typedef long long ll;

#define v(T) vector<T>
#define ttt(T) tuple<T, T, T>
#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define poiu(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long

int n;
int temp;
int cnt;

bool sieve[1000001];

int findroot(int temp) {
    int lo = -1, hi = 1000001;
    while(lo+1 < hi) {
        int mid = (lo+hi)>>1;
        if(mid*mid<=temp) lo = mid;
        else hi = mid;
    }
    return lo;
}
#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[0]=1;
    sieve[1]=1;
    for(int i=2; i<=1000000; ++i) for(int j=i*i; j<=1000000; j+=i)
        sieve[j]=1;

    cin >> n;
    while(n--) {
        cin >> temp;
        int temp_one = findroot(temp);
        if(temp_one*temp_one==temp) {
            if(!sieve[temp_one])
                cout << "YES";
            else
                cout << "NO";
        }
        else
            cout << "NO";
        cout << endl;

    }
    
    return 0;

}


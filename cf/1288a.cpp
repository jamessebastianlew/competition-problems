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

int n;
int d;
bool found;
int t;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    int lo, hi, temp;
    while(t--) {
        cin >> n >> d;
        temp = 0;
        found = false;
        while(!found && temp*temp <= d) {
            if(temp + (d+temp)/(temp+1) <= n)
                found = true;
            temp++;
        }
        if(found)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    


    return 0;

}


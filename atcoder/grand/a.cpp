#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7

template<typename T>
void max_self(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
char s[200001];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int a,b,c,d;


    cin >> n >> a >> b >> c >> d;
    a--;b--;c--;d--;

    for(int i=0; i<n;i++)
        cin >> s[i];

    
    int cnt=0, mx_cnt=0;
    if(c>d) {
        for(int i=b;i<=c;i++)
            max_self(mx_cnt,cnt=s[i]=='.'?cnt+1:0);
        if(mx_cnt<3) { cout << "No" << endl; return 0; }
    }

    cnt=0,mx_cnt=0;
    for(int i=a;i<c;i++)
        max_self(mx_cnt,cnt=s[i]=='#'?cnt+1:0);
    if(mx_cnt>1) { cout << "No" << endl; return 0; }
    cnt=0,mx_cnt=0;
    for(int i=b;i<d;i++)
        max_self(mx_cnt,cnt=s[i]=='#'?cnt+1:0);
    if(mx_cnt>1) { cout << "No" << endl; return 0; }

    cout << "Yes" << endl;

    return 0;

}


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

string s;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef FLOSH
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
#endif

    cin >> n;
    vector<int> tempss;
    tempss.reserve(200005);
    
    int prev = 0;
    int curr = 0;
    cin >> s;

    bool found = false;
    for(int i=0; i<n; ++i) {
        if(s[i]=='1' && (i==0?true:s[i-1]=='0'))
            tempss.pb(curr);
        if(s[i]=='1')
            found = true;
        curr=s[i]=='0'?curr+1:0;
    }
    tempss.pb(curr);

    if(!found) {
        cout << ((n-1)/2)+1 << endl;
        return 0;
    }

    int glob_max = 0;

    //case 1: two in the same place
    int special_one = (tempss[0]-2)/2;
    int special_two = (tempss[tempss.size()-1]-2)/2;
    int special_three=0;
    for(int i=1; i<tempss.size()-1; ++i)
        max_self(special_three, (tempss[i]-2)/3);

    glob_max = max({special_one, special_two, special_three});

    //case 2:
    //pick two different places
    
    tempss[0]=tempss[0]-1;
    tempss[tempss.size()-1]=tempss[tempss.size()-1]-1;
    for(int i=1; i<tempss.size()-1; ++i)
        tempss[i]=(tempss[i]-1)/2;

    sort(tempss.rbegin(), tempss.rend());
    glob_max = max(glob_max, min(tempss[0],tempss[1]));

    cout << glob_max+1 << endl;


        

        

    


    return 0;

}


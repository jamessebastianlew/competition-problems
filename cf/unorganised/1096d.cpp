
#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;
#define int long long

const int mxN = 1e5+5;
int n;
string s;
int a[mxN];
int dp[5];
#undef int
int main() {
#define int long long
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //if you know how to remove a prefix containing the letters har, the do you
    //know the minimum cost to remove a prefix with hard?
    //
    //yes you do, either you take the way to remove it by removeing the prefix
    //with har, or you take the way to remove it by removeing hard and also taking
    //of the current d you are at.
    //
    //we know that if there was a prefix har previously that we could remove, no
    //matter how many d's we got, if we could remove that har prefix, we can remove
    //the entire thing.
    //
    //similarly when we have a letter a, we either have to remove the a, which will
    //cost whatever it takes to remove the current a PLUS what we had to do to remove
    //the last 'ha' prefix, or we can remove whatever it took to remove the h prefix
    //
    //either you remove a 'd' or, you can remove the minimum of 'har' 'ha' or 'h'
    //prefixes, if 'har' 'h' and 'ha' are already minimised for their respective
    //smaller counterparts, then you only have to consider har, since it already 
    //minimises ha and h

    cin >> n;
    cin >> s;
    string temp = "hard";
    for(int i=0; i<n; ++i) cin >> a[i];
    dp[0] = 0x3f3f3f3f3f3f3f3f;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<4; ++j)
            if(s[i] == temp[j])
                dp[j+1] = min(dp[j], dp[j+1]+a[i]);
    }

    cout << dp[4] << endl;



    


    return 0;

}


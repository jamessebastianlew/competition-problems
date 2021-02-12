
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

int n, k;
string s;

int unique_contains = 0;
int allowed[250];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    cin >> s;

    char temp;
    long long total = 0;

    for(int i=0; i<k; ++i)
        cin >> temp, allowed[temp] = true;
    s+=".";
    
    int start = 0;
    int end = 0;

    while(end < n) {
        if(!allowed[s[start]]) {++start, end = start; continue; }
        if(allowed[s[end+1]]) {++end; continue;} 
        long long temp_len = end-start+1;
        total+=(temp_len+1)*temp_len/2;
        start = end + 1, end = start;
    }

    cout << total << endl;
        



    


    return 0;

}


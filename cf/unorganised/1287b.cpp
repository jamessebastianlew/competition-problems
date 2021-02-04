
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void min_self(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, m;
string s;
string temp_name;
vector<int> positions[26];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for(int i=1; i<=n; ++i)
        positions[s[i-1]-'a'].pb(i);
    
    cin >> m;
    while(m--) {
        cin >> temp_name;
        int end_point = 0;
        vector<int> num_letters(26);
        for(char x : temp_name) {
            ++num_letters[x-'a'];
            amax(end_point, positions[x-'a'][num_letters[x-'a']-1]);
        }
        cout << end_point << endl;
    }

    return 0;

}


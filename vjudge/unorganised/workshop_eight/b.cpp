
#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
string s;
int main() {
    cio();
    cin >> n;
    cin >> s;
    int total = 0;
    int curr = 0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='x') ++curr;
        else if(s[i]!=0) total+=max(curr-2, 0), curr = 0;
    }
    if(curr > 0) total+=max(curr-2, 0);
    cout << total << endl;
}




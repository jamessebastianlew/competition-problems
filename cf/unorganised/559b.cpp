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
string s, t;

bool eq(int l, int r, int L, int R) {
    for(int i=l, j=L; i<r; ++i, ++j) if(s[i]!=t[j]) return false;
    return true;
}

bool is_eq(int l, int r, int L, int R) {
    if(eq(l, r, L, R)) return true;
    if((r-l)%2==1) return false;

    int mid_one = (l+r)>>1;
    int mid_two = (L+R)>>1;

    if(is_eq(l, mid_one, L, mid_two) && is_eq(mid_one, r, mid_two, R))
        return true;
    if(is_eq(l, mid_one, mid_two, R) && is_eq(mid_one, r, L, mid_two))
        return true;
    return false;
}
    
int main() {
    cin >> s >> t;
    n = s.size();
    if(is_eq(0, n, 0, n)) cout << "YES";
    else cout << "NO";

    return 0;
}

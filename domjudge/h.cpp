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
template<typename T>
void amod(T a, T b) { return a>=b?a-b:a; }

using namespace std;

const int mxn = 2e5+5;
int div_sm[mxn];

void cnt_div_sm(int nm) {
    for(int i=1; i*i <= nm; ++i) {
        if(nm % i == 0) {
            div_sm[nm] += i;
            if(i != 1 && i*i != nm) 
                div_sm[nm] += nm/i;
        }
    }
}
    

int n;
int l, u;

int main() {
    //sum divisors
    
    cio();
    cin >> n;
    for(int i=2; i<=20000; ++i)
        cnt_div_sm(i);

    while(n--) {
        cin >> l >> u;
        cout << "Amicable numbers between " << l << " and " << u << endl;
        set<int> tmp;
        vector<array<int,2>> all;
        for(int i=l; i<=u; ++i) {
            if(tmp.count(i))
                continue;
            int other = div_sm[i];
            if(other == i)
                continue;
            if(other <= u && div_sm[other] == i)
                all.push_back({i, other}), tmp.insert(other);
        }
        for(array<int, 2> v : all)
            cout << v[0] << ' ' << v[1] << endl;
        if(all.empty())
            cout << "None" << endl;
    }

    return 0;
}

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

int n, k, r;

const int mxn = 2e5+5;

int aa[mxn];
set<int> pp;
int main() {
    cio();
    cin >> n >> k >> r;
    for(int i=0; i<k; ++i) cin >> aa[i], pp.insert(aa[i]);

    int cnt = 0;
    for(int pos = 1; pos+r-1 <= n; ++pos) {
        auto first = pp.lower_bound(pos);
        if(first == pp.end())
            pp.insert(pos+r-1), pp.insert(pos+r-2), cnt+=2;
        else {
            auto second = pp.upper_bound(*first);
            if(second==pp.end()) { // insert one or two
                if(*first > pos+r-1)
                    pp.insert(pos+r-1), pp.insert(pos+r-2), cnt+=2;
                else {
                    if(*first==pos+r-1) pp.insert(pos+r-2);
                    else pp.insert(pos+r-1);
                    ++cnt;
                }
            } else { // normal case
                if(*first > pos+r-1)
                    pp.insert(pos+r-1), pp.insert(pos+r-2), cnt+=2;
                else if( *second > pos+r-1) {
                    if(*first!=pos+r-1) pp.insert(pos+r-1);
                    else pp.insert(pos+r-2);
                    ++cnt;
                }
            }
        }
    }
    cout << cnt << endl;




    return 0;
}

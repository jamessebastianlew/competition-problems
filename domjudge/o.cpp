
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

const int mxn = 200 + 5;
const int mxm = 20 + 5;
const int mxS = 40 * 200 + 5;

int aa[mxn];
bool dp[mxn][2*mxS][mxm]; 
bool picked[mxn][2*mxS][mxm];

// -x will be at x << 1 + 1
// x will be at x << 1

int get(int a) { // fake
    return a + 4001;

}

int get_real(int a) {
    return a - 4001;
}

int n, m;
int main() {
    cin >> n >> m;
    int a, b;
    for(int i=1; i<=n; ++i) cin >> a >> b, aa[i] = a-b;

    dp[0][0][0] = true;
    for(int i=0; i<=n; ++i) dp[i][0][0] = true;
    for(int i=1; i<=n; ++i)
        for(int sm=0; sm<2*4001; ++sm) for(int k=0; k<=m; ++k) {
            int curr = get_real(sm);
            if(dp[i-1][sm][k]) {
                dp[i][sm][k] = true, picked[i][sm][k] = false;
            } else if(k && (get(curr - aa[i]) < 2*mxS) && dp[i-1][get(sm-curr)][k-1]) {
                dp[i][sm][k] = true, picked[i][sm][k] = true;
            }
        }

    int best_sm = -1;

    for(int i=0; i<20; ++i)
        if(dp[n][i][m]) { best_sm = i; break; }
    cout << best_sm << endl;

    int curr_person = n;
    int curr_ppl = m;
    int curr_sm = best_sm;
    vector<int> ans;
    while(curr_person != 0) {
        if(picked[curr_person][curr_sm][curr_ppl])
            ans.push_back(curr_person), curr_sm = get(get_real(curr_sm) - aa[curr_person]), --curr_person, --curr_ppl;
        else
            --curr_person;
    }
    for(int v : ans)
        cout << v << ' ';
    cout << endl;

    return 0;
}

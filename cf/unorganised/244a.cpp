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

const int mxn = 30;
const int mxk = 30;
int aa[mxn];
map<int,int> cnt;
set<int> used;
int orange[mxn*mxk+1];
vector<int> slices[mxn];

int n, k;

int main() {
    cio();
    cin >> k >> n;
    int temp;
    for(int i=0; i<n; ++i) cin >> temp, orange[temp]=i+1, ++cnt[i+1], slices[i+1].push_back(temp);

    int curr = 1;
    for(int i=1; i<=n*k; ++i) {
        if(orange[i]==0 && cnt[curr] < k) orange[i]=curr, ++cnt[curr], slices[curr].push_back(i);
        if(cnt[curr] == k) ++curr;
    }

    for(int i=1; i<=n; ++i) {
        for(int v : slices[i])
            cout << v << ' ';
        cout << endl;
    }
    return 0;
}

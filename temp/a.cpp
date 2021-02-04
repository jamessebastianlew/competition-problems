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

const int mxn = 27;
int n;
int freq[mxn];

int log2(int a) {
    if(a==0) return 0;
    int cnt = 0;
    while(a) ++cnt, a >>= 1;
    return cnt;
}

int main() {
    cin >> n;
    string s;
    for(int i=0; i<n; ++i) cin >> s, freq[i] = stoi(s.substr(2));
    sort(freq, freq+n);

    int cnt = 2 * n;
    int run = 1;

    for(int i=0; i<n; ++i) {
        int temp = log2(freq[i] - run);
        cnt += temp;
        run = freq[i];
    }

    cout << cnt << endl;


    return 0;
}

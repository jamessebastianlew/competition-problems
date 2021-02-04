
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

const int mxn = 16;
int n, S;
array<int, 2> soldiers[mxn];
int main()  {
    cio();
    cin >> S;
    int temp_one, temp_two;
    while(!(cin >> temp_one >> temp_two).fail()) {
        soldiers[n++] = {temp_one, temp_two};
        cout << temp_one << ' ' << temp_two << endl;
    }
    cout << "here" << endl;
    return 0;
}

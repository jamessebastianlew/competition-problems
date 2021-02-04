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
void amod(T& a, T b) { a=a>=b?a-b:a; }

using namespace std;

int n;
const int mxn = 3e5+5;

array<int, 2> pp[mxn];
array<int, 4> lines[mxn];

int main() {
    cio();
    uniform_real_distribution<double> unif(-1e9, 1e9);
    default_random_engine re;
    // randomisation
    // BINARY SEARCH POLYGON RANDOMISE POINTS MANHATTAN DISTANCE
    // REMAINS:
    // 
    // RANDOMISED ALGO
    cin >> n;
    for(int i=0; i<n; ++i) 
        cin >> pp[i][0] >> pp[i][1];
    for(int i=1; i<n; ++i) {
        lines[i][2] = pp[i][0]; lines[i][3] = pp[i][1];
        lines[i][0] = pp[i-1][0]; lines[i][1] = pp[i-1][1];
        if(lines[i][1] < lines[i][3]) 
            swap(lines[i][0], lines[i][2]), swap(lines[i][1], lines[i][3]);
    }
    sort(lines, lines+n);

    double ave = 0;
    for(int i=0; i<1000; ++i) {
        double y = unif(re);
        int lo=-1, hi = n;
        while(lo+1<hi) {
            int mid=(lo+hi)>>1;
            if(y <= lines[i][1]) lo = mid;
            else hi = mid;
        }
        int lo1 = lo;
        int lo2 = -1;
        lo = -1, hi = n;
        while(lo+1 < hi) {
            int mid=(lo+hi)>>1;
            if(y < lines[i][1]) lo = mid;
            else hi = mid;
        }
    }
        
        

    //order points from top to bottom
    sort(lines, lines+n, [](auto a, auto b) {






    return 0;
}

#include <bits/stdc++.h>

using namespace std;

//answer is just the number of prime factors
//
// 1 2 3 4 5 6 7 8 9 10 11 12
// - 1 1 2 1 2 1 3 2 2  1  3
//
// prefix sum on the interval

const int mxN = 5e6+5;
int a, b, n, q;
int sv[mxN];
int temp[mxN][2];
int pref_sums[mxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2; i<mxN; ++i) {
        if(sv[i]) continue;
        temp[i][0] = i, temp[i][1] = 1;
        for(int j=i; j<mxN; j+=i) {
            temp[j][0] = i; 
            temp[j][1] = (temp[j/i][0]==i?temp[j/i][1]:0) + 1;
            sv[j]+=temp[j][1];
        }
    }

    for(int i=1; i<mxN; ++i)
        pref_sums[i] = pref_sums[i-1]+sv[i];

    /*
    // better implementation
    // worse complexity though: roughly O(n logn logn) but with much better
    // constant factors

    for(int i=2; i<mxN; pref_sums[i]+=pref_sums[i-1], ++i)
        if(!pref_sums[i]) for(long long power=i; power<mxN; power*=i)
            for(int temp=power; temp<mxN; temp+=power) ++pref_sums[temp];
    */

    cin >> q;

    while(q--) {
        cin >> a >> b;
        cout << (pref_sums[a]-pref_sums[b]) << '\n';
    }

    return 0;
}


#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;
int a[500005];
int cnt_end[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> pos({4,8,15,16,23,42});
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        int lo=-1, hi=6;
        while(lo+1<hi) {
            int mid = (lo+hi)>>1;
            if(pos[mid]<=a[i]) lo = mid;
            else hi = mid;
        }
        a[i]=lo;
    }

    for(int i=0; i<n; ++i) {
        if(a[i]==0)
            ++cnt_end[0];
        else if(cnt_end[a[i]-1]>0)
            --cnt_end[a[i]-1], ++cnt_end[a[i]];
    }
    cout << (n-cnt_end[5]*6) << endl;



    return 0;

}



#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define szz(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, m;

int boys[101];
int girls[101];


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> boys[i];
    cin >> m;
    for(int i=0; i<m; ++i)
        cin >> girls[i];

    sort(boys, boys+n);
    sort(girls, girls+m);
    girls[m]=110;

    int m_index = 0;
    int cnt = 0;

    for(int i=0; i<n; ++i) {
        while(m_index < m && girls[m_index]<=boys[i]+1)
            if(abs(girls[m_index++] - boys[i]) <= 1) { ++cnt; break; }
    }
    cout << cnt << endl;
        


    return 0;

}


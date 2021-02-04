#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5+5;

int n,q,a,b,x;
int aa[mxN];

bool seen[(int)1e6+1];
bool dblseen[(int)1e6+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    for(int i=0; i<n; ++i) {
        cin >> aa[i], dblseen[aa[i]] = seen[aa[i]], seen[aa[i]] = true;
    }

    for(int i=0; i<n; ++i) for(int j=1; j*j<=aa[i]; ++j)
        if(aa[i]%j==0) {
            int temp_one = j;
            int temp_two = aa[i]/j;
            if(aa[i]==temp_one && dblseen[temp_one]) {++cnt; break; }
            else if(aa[i]!=temp_one && seen[temp_one]) {++cnt; break; }
            if(aa[i]==temp_two && dblseen[temp_two]) {++cnt; break; }
            else if(aa[i]!=temp_two && seen[temp_two]) { ++cnt; break; }

        }

    cout << (n-cnt) << endl;

    return 0;
}

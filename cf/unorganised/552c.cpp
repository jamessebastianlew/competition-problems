#include <bits/stdc++.h>

using namespace std;

int w, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> m;
    // greedy

    while(w > 0) {
        int tmp = w%m;
        w/=m;

        if(tmp!=1) { cout << "NO" << endl; return 0; }
    }

    cout << "YES" << endl;

    return 0;
}

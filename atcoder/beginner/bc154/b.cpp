#include <bits/stdc++.h>
using namespace std;

int n, k;
int temp;
bool found;
double curr_max;

double pref[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        pref[i]=pref[i-1]+(temp+1)/2.0;
    }

    for(int i = 0; i+k <= n; i++)
        curr_max = max(pref[i+k]-pref[i],curr_max);

    cout << curr_max << endl;

    return 0;
}
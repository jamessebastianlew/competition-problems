#include <bits/stdc++.h>
using namespace std;



string s, t, yes;
int a, b;

unordered_map<string, int> temp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s >> t >> a >> b >> yes;

    temp[s]=a;
    temp[t]=b;

    temp[yes]--;

    printf("%d %d\n", temp[s], temp[t]);
    
    return 0;
}
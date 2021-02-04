#include <bits/stdc++.h>
using namespace std;

int n, k;
string number;

int choose(int n, int r) {
    vector<int> arr(n+1);
    arr[0]=1;
    for(int i = 1; i < n+1; i++) {
        for(int j=i; j > 0; j--)
            arr[j]+=arr[j-1];
    }
    return arr[r];
}

int nw(int place, int digit) {
    cout << place << endl;
    if(place==0)
        return 0;
    return digit*((int)pow(8,k-1)) + nw(place-1, 9);
}
//*choose(place-1,place-k)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> number >> k;
    n = number.size();

    cout << nw(n, (int)(number[0]-'0'))  << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int n;
int temp;


int main()
{
    cin >> n;
    bool found = false;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(!(temp&1)) {
            if(!(temp%3==0 || temp%5==0))
                found = true;
        }
    }
    if(found)
        cout << "DENIED" << endl;
    else
        cout << "APPROVED" << endl;

    return 0;
        
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll temp,k;

priority_queue<ll> mh;

int main()
{
    scanf("%d%lld", &n, &k);
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            temp = (ll)a[i]*a[j];
            if(mh.size() < (unsigned ll) k)
                mh.push(temp);
            else if (temp < mh.top()) {
                mh.pop();
                mh.push(temp);
            }
        }
    }
    
    cout << mh.top() << endl;

    return 0;
        
}
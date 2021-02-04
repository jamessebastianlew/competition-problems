#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> freq;
int n;
string temp;

set<string> strset;
int curr_max = 0;
vector<string> ans;

void max_self(int &a, int b) { a=max(a,b); }

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(!strset.count(temp)) {
            strset.insert(temp);
            freq[temp]=0;
        }
        max_self(curr_max, ++freq[temp]);
    }

    for(string x : strset) {
        if(freq[x]==curr_max)
            ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    for( string x : ans)
        cout << x << endl;
        
    return 0;
        
}
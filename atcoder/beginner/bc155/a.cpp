#include <bits/stdc++.h>
using namespace std;

int a, b, c;

unordered_map<int, int> freq;

int main()
{
    cin >> a >> b >> c;

    string s = "No";

    freq[a]=0;
    freq[b]=0;
    freq[c]=0;

    freq[a]++;
    freq[b]++;
    freq[c]++;
    
    if(freq[a]==2 || freq[b]==2 || freq[c]==2)
        s = "Yes";
    
    cout << s << endl;
    return 0;

}
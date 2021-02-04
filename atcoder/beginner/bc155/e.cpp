#include <bits/stdc++.h>
using namespace std;

int temp, curr_ans;

string s;

int main()
{
    cin >> s;

    int count = s.size()-1;

    while(count > -1) {
        temp = s[count]-'0';

        if (temp>5)
            curr_ans+=11-temp;
        else
            curr_ans+=temp;

        count--;
    }

    cout << curr_ans << endl;


    return 0;
        
}
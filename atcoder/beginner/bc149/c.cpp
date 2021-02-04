#include <bits/stdc++.h>

typedef long long ll;
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD 10e9+7

void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n, k;
int x;
const int MAX_N = 1e6+5;

bool visited[MAX_N];

int main() {
    cin >> x;

    int top = 2*x;

    int temp_one=2;
    int temp_two;

    while(temp_one < top) {
        if(visited[temp_one]) {
            temp_one++;
            continue;
        }

        if(temp_one >= x) {
            cout << temp_one << endl;
            break;
        }

        temp_two = temp_one+temp_one;
        while(temp_two < top) {
            visited[temp_two] = true;
            temp_two+=temp_one;
        }

        temp_one++;
    }


    return 0;
}

#include <bits/stdc++.h>

typedef long long ll;

#define fio(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
#define cio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

const int mod = 1e9+7;
template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n;

bool dig[10];
int main() {
    cio();
    cin >> n;
    for(int i=n+1; i<9013; ++i) {
        int temp = i;
        bool bad = false;
        memset(dig, 0, sizeof(dig));
        while(temp!=0) {
            int temp_dig = temp%10;
            temp/=10;
            if(dig[temp_dig]) bad = true;
            dig[temp_dig] = true;
        }
        if(!bad) { cout << i; return 0; }
    }



        
        

    return 0;
}

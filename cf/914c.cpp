#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3+5;

int n;
char s[mxN];
int bin[mxN][mxN]; // nck [n][k]
int num_steps[mxN];
int bsf, ans;

int main() {
    scanf("%s%d", s+1, &k); n=strlen(s+1);

    bin[0][0] = 1;
    for(int i=1; i<=n; ++i) for(int j=0; j<=i; ++j)
        bin[i][j] = (bin[i-1][j] + bin[i-1][j+1])

    for(int x=2; x<=n; ++x)
        num_steps[x] = num_steps[__builtin_popcount(x)]+1;
    for(int i=1; i<=n; ++i) // oops need to choses only things with the bits being num_steps[k-1]
        if(s[i]=='1') ans = (ans + bin[n-i][k-bsf]) % mod, ++bsf;
    printf("%d\n", ans);

    return 0;
}

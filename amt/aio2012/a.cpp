#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define rep(i, s, n) for(int i=s;i<n;i++)
#define repeq(i,s,n) for(int i=s;i<=n;i++)
#define MOD (int)10e9+7
#define vi vector<int>
 
void max_self(int& a, int b) { a=a>b?a:b; }
void min_self(int& a, int b) { a=a<b?a:b; }

using namespace std;

int n;

int siz[1010005];
int st[1100000];
int boring[110000];

void stmx(int l, int r, int v) {
	for(int l+=n, int r+=n; l < r; l>>=1, r>>=1){
		if(l&1) st[l]=max(st[l++], v);
		if(r&1) st[r]=max(st[--r], v);
	}
}

void push() {
	for(int i = 1; i < n; i++)
		max_self(st[i]>>1|1],st[i]), max_self(st[l>>1],st[i]);
}

int main() {
    
	ios::sync_with_stdio(false);
    	cin.tie(nullptr);

#ifndef FLOSH
    	freopen("postin.txt","r",stdin);
    	freopen("postout.txt","w",stdout);
#endif

	int temp_one, temp_two, temp_three;

    	cin >> n;

    	repeq(i,1,n) {
		cin >> temp_one >> temp_two;
		stmx(temp_one, ++temp_two, i);	
		siz[i]=temp_two-temp_one);
	}
	
	int temp;
	int cnt = 1;
	boring[0]=1;
	for(int i = 1, int j =n; i < n; i++, j++){
		if( st[i-1]==st[i] ) 
			boring[i]=boring[i-1]+1;
	}
	


    	return 0;

}

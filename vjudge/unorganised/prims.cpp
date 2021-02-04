#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

const int mxE = 5000000;
int uf[mxE];

void ms(int x) { uf[x]=x; }
int find(int x) { if(uf[x]==x) return x; else return uf[x]=find(uf[x]); }
void un(int a, int b) { uf[find(a)] = find(b); } 


int V, E;
long long total;
array<int, 3> edges[mxE];

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    for(int i=0; i<E; ++i) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
    }
    sort(edges, edges+E);

    int start;
    cin >> start;
    vector<int> ind;
    for (int i = 1; i <= V; i++) ms(i);
    for (int i = 0; i < E; i++) {
        if (find(edges[i][1]) != find(edges[i][2]))
            un(edges[i][1], edges[i][2]), total+=edges[i][0];
    }
    cout << total << endl;

    return 0;

}


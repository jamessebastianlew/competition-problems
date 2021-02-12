#include <bits/stdc++.h>

typedef long long ll;

#ifdef FLOSH
    #define debug(something) something
#endif
#ifndef FLOSH
    #define inout(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
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
template<typename T>
void sadd(T& a, T b) { a=(a+b)%MOD; }
template<typename T>
void ssub(T& a, T b) { a=((a-b)%MOD+MOD)%MOD; }

using namespace std;

const int mxN = 1e5+1;
int n;

ll ax, ay, bx, by, tx, ty;
double bottles[mxN][2];
double adists[mxN];
double bdists[mxN];
double dists[mxN];

double getdist(ll a, ll b, ll c, ll d) {
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;

    double sumdists = 0;
    for(int i=0; i<n; ++i) {
        cin >> bottles[i][0] >> bottles[i][1];
        dists[i] = getdist(bottles[i][0], bottles[i][1], tx, ty);
        sumdists+=dists[i];
    }

    double mina = 1e18;
    double second_mina = 1e18;
    int bottlea = 0;
    int second_bottlea = 0;
    double minb = 1e18;
    double second_minb = 1e18;
    int bottleb = 0;
    int second_bottleb = 0;

    for(int i=0; i<n; ++i) {
        adists[i] = getdist(ax, ay, bottles[i][0], bottles[i][1]);
        bdists[i] = getdist(bx, by, bottles[i][0], bottles[i][1]);
        if( adists[i] + dists[i] - 2*dists[i] < mina - 2*dists[bottlea] ) {
            second_mina = mina, second_bottlea = bottlea;
            mina=adists[i]+dists[i], bottlea = i;
        } else if (adists[i] + dists[i] - 2*dists[i] < second_mina - 2*dists[second_bottlea])
            second_mina = adists[i] + dists[i], second_bottlea = i;

        if( bdists[i] + dists[i] - 2*dists[i] < minb - 2*dists[bottleb] ) {
            second_minb = minb, second_bottleb = bottleb;
            minb=bdists[i]+dists[i], bottleb = i;
        } else if (bdists[i] + dists[i] - 2*dists[i] < second_minb - 2*dists[second_bottleb])
            second_minb = bdists[i] + dists[i], second_bottleb = i;
    }

    double min_total = 1e18;
    amin(min_total, mina+2*sumdists-2*dists[bottlea]);
    amin(min_total, minb+2*sumdists-2*dists[bottleb]);
    if(bottlea == bottleb) {
        if( mina + second_minb < minb + second_mina )
            minb = second_minb, bottleb = second_bottleb;
        else
            mina = second_mina, bottlea = second_bottlea;
    }

    // case 1: a takes all the bottles
    amin(min_total, mina+minb+2*sumdists-2*(dists[bottlea] + dists[bottleb]));

    printf("%.12lf\n", min_total);



    
    




    


    return 0;

}


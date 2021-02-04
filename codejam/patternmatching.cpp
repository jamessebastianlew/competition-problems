
#include <bits/stdc++.h>

typedef long long ll;

#define pb push_back
#define mp make_pair
#define forn(n) for(int i=0; i < n; i++)
#define MOD 1000000007
#define poius(x) ((int)(x).size())
#define endl '\n'

template<typename T>
void amax(T& a, T b) { a=a>b?a:b; }
template<typename T>
void amin(T& a, T b) { a=a<b?a:b; }

using namespace std;

int n, t;
vector<string> samples;
vector<int> indecies;
vector<int> start_len; // length before the first star
vector<int> end_len;

void find_first_star() {
    start_len.resize(n);
    start_len.clear();
    for(int i = 0; i<n; ++i )
        while(start_len[i]<=poius(samples[i]) && samples[i][start_len[i]]!='*')
            ++start_len[i];
}
void find_last_star() {
    end_len.resize(n);
    end_len.clear();
    for(int i = 0; i<n; ++i )
        while(end_len[i]<=poius(samples[i]) && samples[i][poius(samples[i])-end_len[i]-1]!='*')
            ++end_len[i];
}

bool comp_strs(string& a, string& b) {
    int min_len = min(a.size(), b.size());
    for(int i=0; i<min_len; ++i)
        if(a[i]!=b[i])
            return false;
    return true;
}
            
bool comp_strs_end(string& a, string& b) {
    const int n = a.size();
    const int m = b.size();
    int min_len = min(n,m);
    for(int i=0; i<min_len; ++i)
        if(a[n-i-1]!=b[m-i-1])
            return false;
    return true;
}

string get_inbetween() {
    string inbetween = "";
    for(int i = 0;i <n; ++i ){
        int start = start_len[i];
        int end = poius(samples[i]) - end_len[i];
        for(; start<end; ++start) {
            if(samples[i][start]=='*')
                continue;
            else
                inbetween+=samples[i][start];
        }
    }
    return inbetween;
}


void solve() {
    cin >> n;

    samples.resize(n);
    indecies.resize(n);
    indecies.clear();

    for(int i=0; i<n; ++i)
        cin >> samples[i];
    
    find_first_star();
    find_last_star();
    
    int mx_start=-1;
    int mx_start_ind=-1;
    int mx_end=-1;
    int mx_end_ind=-1;

    for(int i=0; i<n; ++i) {
        if(start_len[i]>mx_start)
            mx_start_ind = i, mx_start = start_len[i];
        if(end_len[i]>mx_end)
            mx_end_ind = i, mx_end = end_len[i];
    }

    string big_start(samples[mx_start_ind].begin(), samples[mx_start_ind].begin()+mx_start);
    string temp;

    //testing starts
    for(int i = 0; i<n; ++i) {
        temp.assign(samples[i].begin(), samples[i].begin()+start_len[i]);
        if(!comp_strs(temp, big_start)) {cout << "*" << endl; return; }
    }

    string big_end(samples[mx_end_ind].end()-mx_end, samples[mx_end_ind].end());

    for(int i = 0; i<n; ++i) {
        temp.assign(samples[i].end()-end_len[i], samples[i].end());
        if(!comp_strs_end(temp, big_end)) {cout << "*" << endl; return; }
    }



    string middle;
    middle.reserve(10000);
    /*j
    int alphabets = (10000 - big_end.size() - big_start.size())/26;
    for(int i = 0; i<alphabets; ++i)
        middle+="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans = big_start+middle+big_end;
    */
    string inbetween = get_inbetween();

    string ans = big_start+inbetween+big_end;
    cout << ans << endl;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for(int i=1; i<=t; ++i)
        cout << "CASE #" << i << ": ", solve();

    return 0;

}


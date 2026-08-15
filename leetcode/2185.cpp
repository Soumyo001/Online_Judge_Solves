#include <bits/stdc++.h>
using namespace std;

int prefixCount(vector<string>& words, string pref) {
    int ct = 0;
    for(const string s : words) {
        int idx = s.find(pref);
        if(idx != string::npos && idx == 0) ++ct;
    }
    return ct;
}

int main(void) {
    int n; cin >> n; vector<string> v(n, "");
    for(int i=0; i<n; ++i) cin>>v[i];
    string pref; cin >> pref;
    cout<<prefixCount(v, pref);
}
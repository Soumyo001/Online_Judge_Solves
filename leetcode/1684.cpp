#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    int ct = 0;
    for(const string s : words) {
        bool valid = true;
        for(const char c : s) {
            if(allowed.find(c) == string::npos) {
                valid = false;
                break;
            }
        }
        if(valid) ++ct;
    }
    return ct;
}

int main(void) {
    int n; cin >> n; vector<string> v(n, ""); for(int i=0;i<n;++i) cin>>v[i];
    string a; cin >> a;
    cout<<countConsistentStrings(a, v);

}
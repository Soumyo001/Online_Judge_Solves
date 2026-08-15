#include <bits/stdc++.h>
using namespace std;

int mostWordsFound(vector<string>& sentences) {
    int mx = INT_MIN;
    for(const string s : sentences) {
        int ct = 0;
        int i = 0;
        while(s[i] == ' ') ++i;
        for(i; i < s.length(); ++i) {
            if(s[i] == ' ' && i+1 < s.length() && s[i+1] != ' ') ++ct;
        }
        mx = max(ct, mx);
    }
    return mx + 1;
}

int main(void) {
    int n; cin >> n; vector<string> v(n, "");
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<mostWordsFound(v);
}
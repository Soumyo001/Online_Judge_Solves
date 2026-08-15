#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string>& words) {
    vector<string> ans;
    vector<int> freq_table(26, INT_MAX);
    
    for(const string s : words) {
        vector<int> freq(26, 0);
        for(const char c : s) ++freq[c - 'a'];
        for(int i = 0; i < 26; ++i) freq_table[i] = min(freq_table[i], freq[i]);
    }

    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < freq_table[i]; ++j) ans.push_back(string(1, 'a' + i));
    }
    return ans;
}

int main(void) {
    int n; cin >> n;
    vector<string> v(n, "");
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(const string s : commonChars(v)) cout<<s<<" ";
}
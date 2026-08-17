#include <bits/stdc++.h>
using namespace std;

vector<char> commonChars(string a, string b) {
    vector<string> v = {a, b};
    vector<int> freq_table(26, INT_MAX);

    for(const string s : v) {
        vector<int> freq(26, 0);
        for(const char c : s) ++freq[c - 'a'];
        for(int i=0; i<26; ++i) freq_table[i] = min(freq_table[i], freq[i]);
    }

    vector<char> ans;
    for(int i=0; i<26; ++i) for(int j = 0; j<freq_table[i]; ++j) ans.push_back('a' + i);
    return ans;
}

int main(void) {
    string a, b; cin >> a >> b;
    for(const char c : commonChars(a, b)) cout<<c<<" ";
}
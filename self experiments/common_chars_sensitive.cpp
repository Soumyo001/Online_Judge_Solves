#include <bits/stdc++.h>
using namespace std;

vector<char> commonChars(string s1, string s2) {
    string res1 = "", res2 = "";
    for(const char c: s1) if(isalpha(c)) res1 += c;
    for(const char c: s2) if(isalpha(c)) res2 += c;
    
    vector<string> v = {res1, res2};
    vector<int> freq_table(52, INT_MAX);

    for(const string s : v) {
        vector<int> freq(52, 0);
        for(const char c : s) {
            if(isupper(c)) ++freq[c - 'A'];
            if(islower(c)) ++freq[(26 + (c - 'a'))];
        }
        for(int i = 0; i < 52; ++i) freq_table[i] = min(freq_table[i], freq[i]);
    }

    vector<char> ans;
    for(int i = 0; i < 52; ++i) for(int j = 0; j < freq_table[i]; ++j) {
        if(i < 26) ans.push_back('A' + i);
        else ans.push_back('a' + i - 26);
    }
    return ans;
}

int main(void) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(const char c : commonChars(s1, s2)) cout<<c<<" ";
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res;
    vector<vector<string>> ans;
    for(const string s: strs) {
        string k = s;
        sort(k.begin(), k.end());
        res[k].push_back(s);
    }
    for(const auto& it: res) ans.push_back(it.second);
    return ans;
}

int main(void) {
    string s;
    getline(cin, s);
    istringstream iss(s);
    string word;
    vector<string> words;
    while(iss >> word)  words.push_back(word);
    for(const vector<string>& i: groupAnagrams(words)) {
        for(const string j: i) cout<<j<<" ";
        cout<<"\n";
    }
}
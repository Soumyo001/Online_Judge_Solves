#include <bits/stdc++.h>
using namespace std;

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<string>> m;
    m['2'] = {"a", "b", "c"};
    m['3'] = {"d", "e", "f"};
    m['4'] = {"g", "h", "i"};
    m['5'] = {"j", "k", "l"};
    m['6'] = {"m", "n", "o"};
    m['7'] = {"p", "q", "r", "s"};
    m['8'] = {"t", "u", "v"};
    m['9'] = {"w", "x", "y", "z"};
    
    vector<string> ans;
    function<void(string digits,int idx,string res)> index;
    index = [&](string digits, int idx, string res) {
        if(idx == digits.length()) {
            ans.push_back(res);
            return;
        }
        for(const string s : m[digits[idx]]) index(digits, idx + 1, res + s);
    };
    index(digits, 0, "");
    return ans;
}

int main(void) {
    string s; cin >> s;
    for(const string i: letterCombinations(s)) cout<<i<<" ";
}
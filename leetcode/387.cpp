#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for(const char c : s) ++m[c];
    for(int i = 0; i < s.length(); ++i) if(m[s[i]] == 1) return i;
    return -1;
}

int main(void) {
    string s; cin >> s;
    cout<<firstUniqChar(s);
}
#include <bits/stdc++.h>
using namespace std;

bool sentenceAnagram(string s1, string s2) {
    string res1 = "", res2 = "";
    for(char c : s1) if(isalnum(c)) res1 += tolower(c);
    for(char c : s2) if(isalnum(c)) res2 += tolower(c);
    if(res1.length() != res2.length()) return false;
    sort(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    return res1 == res2;
}

int main(void) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout<<sentenceAnagram(s1, s2);
}
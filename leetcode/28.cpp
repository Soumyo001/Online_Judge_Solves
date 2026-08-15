#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int len = needle.length();
    
    for(int i = 0; i < haystack.length(); ++i) {
        string res = haystack.substr(i, len);
        if(res == needle) return i;
    }
    return -1;
}

int main(void) {
    string s1, s2; cin >> s1 >> s2;
    cout<<strStr(s1, s2);
}
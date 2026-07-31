#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
    int idx = -1;
    for(int i = 0; i < haystack.length(); ++i) {
        if(needle[0] == haystack[i]) {
            idx = i;
            for(int j = 0; j < needle.length(); ++j) {
                if(needle[j] != haystack[i+j]) {
                    idx = -1;
                    break;
                }
            }
            if(idx != -1) return idx;
        }
    }
    return idx;
}

int main(void) {
    string s1, s2; cin >> s1 >> s2;
    cout<<strStr(s1, s2);
}
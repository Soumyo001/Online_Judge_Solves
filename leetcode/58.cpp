#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    int i = s.length() - 1;
    while(i >= 0 && s[i] == ' ') --i;
    while(i >= 0 && s[i] != ' ') ++len, --i;
    return len;
}

int main(void) {
    string s;
    getline(cin, s);
    cout<<lengthOfLastWord(s);
}
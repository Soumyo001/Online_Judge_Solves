#include <bits/stdc++.h>
using namespace std;

int countWords(string s) {
    bool isWord = false;
    int ct = 0;
    for(const char c : s) {
        if(c != ' ' && !isWord) {
            isWord = true; ++ct;
        } else if(c == ' ') {
            isWord = false;
        }
    }
    return ct;
}

int countWords2(string s) {
    stringstream ss(s);
    string word;
    int ct = 0;
    while(ss >> word) ++ct;
    return ct;
}

int main(void) {
    string s; getline(cin, s);
    cout<<countWords(s);
}
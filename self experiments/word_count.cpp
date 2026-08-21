#include <bits/stdc++.h>
using namespace std;

int wordCount(string s) {
    int ct = 0;
    bool isWord = false;

    for(const char c : s) {
        if(c != ' ' && !isWord) {
            ++ct;
            isWord = true;
        } else if(c == ' ') {
            isWord = false;
        }
    }
    return ct;
}

int main(void) {
    string s;
    getline(cin, s);
    cout<<wordCount(s);
}
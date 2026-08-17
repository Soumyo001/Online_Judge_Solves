#include <bits/stdc++.h>
using namespace std;

bool isUniqueChars(string s) {
    int count = 0;
    for(const char c : s) {
        int bit = c - 'a';
        if(count & (1 << bit)) return false;
        count |= (1 << bit);
    }
    return true;
}

int main(void) {
    string s; cin >> s;
    cout<<isUniqueChars(s);
}
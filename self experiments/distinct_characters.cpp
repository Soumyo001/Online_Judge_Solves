#include <bits/stdc++.h>
using namespace std;

int distinctChars(string s) {
    unsigned int count = 0;
    for(const char c : s) {
        int bit = c - 'a';
        count |= (1 << bit);
    }
    return __builtin_popcount(count);
}

int main(void) {
    string s; cin >> s;
    cout<<distinctChars(s);
}
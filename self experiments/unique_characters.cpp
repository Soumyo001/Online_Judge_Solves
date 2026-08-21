#include <bits/stdc++.h>
using namespace std;

bool uniqueChars(string s) {
    int count = 0;
    for(const char c : s) {
        int bit = c - 'a';
        if(count & (1 << bit)) return false;
        count |= (1 << bit);
    }
    return true;
}

int countDistinctChars(string s) {
    int count = 0;
    for(const char c : s) {
        int bit = c - 'a';
        count |= (1 << bit);
    }
    return __builtin_popcount(count);
}

int main(void) {
    string s;
    cin >> s;
    cout<<uniqueChars(s)<<" "<<countDistinctChars(s);
}
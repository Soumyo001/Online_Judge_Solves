#include <bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int res = 0;
    for(const char c: columnTitle) {
        res = (res * 26) + (c - 'A');
        ++res;
    }
    return res;
}

int main(void) {
    string s; cin>>s;
    cout<<titleToNumber(s);
}
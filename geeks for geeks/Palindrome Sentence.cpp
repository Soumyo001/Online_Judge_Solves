#include <bits/stdc++.h>
using namespace std;

bool isPalinSent(string &s) {
    // code here
    string res;
    for(const char c: s) if(isalnum(c)) res+=tolower(c);
    string rev = res;
    reverse(rev.begin(), rev.end());
    return res == rev;
}

int main(void) {
    string s; cin >> s;
    cout<<isPalinSent(s)<<"\n";
}
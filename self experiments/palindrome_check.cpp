#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s1) {
    string x = "";
    for(const char c : s1) if(isalnum(c)) x += c;
    string res = x;
    reverse(res.begin(), res.end());
    return x == res;
}

int main(void) {
    string s1;
    getline(cin, s1);
    cout<<isPalindrome(s1);
}
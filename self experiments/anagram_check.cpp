#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b) {
    string x = "", y = "";
    for(const char c : a) if(isalpha(c)) x += tolower(c);
    for(const char c : b) if(isalpha(c)) y += tolower(c);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return x == y;
}

int main(void) {
    string a,b;
    getline(cin, a);
    getline(cin, b);
    cout<<isAnagram(a, b);
}
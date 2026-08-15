#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int i = 0;
    string ans = "";
    while(s[i] == ' ') ans+=" ", ++i;
    for(i; i < s.length(); ) {
        if(s[i] != ' ') {
            string res = "";
            int j = 0;
            for(j = i; (s[j] != ' ' && j < s.length()); ++j) res += s[j];
            reverse(res.begin(), res.end());
            ans += res;
            i += (j - i);
        } else {
            ans += " "; ++i;
        }
    }
    return ans;
}

int main(void) {
    string s; getline(cin, s);
    cout<<reverseWords(s);
}
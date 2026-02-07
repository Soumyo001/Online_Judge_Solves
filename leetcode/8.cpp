#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i = 0, n = s.length();
    while(i < n && s[i] == ' ') ++i;

    bool neg = false;
    if(i < n && (s[i] == '+' || s[i] == '-')){
        neg = (s[i] == '-');
        ++i;
    }

    int ans = 0;
    while(i < n && isdigit(s[i])){
        int d = s[i] - '0';

        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && d > 7)) return neg? INT_MIN:INT_MAX;
        ans = ans * 10 + d;
        ++i;
    }
    return neg? -ans:ans;
}

int main(void) {
    string s; cin>>s;
    cout<<myAtoi(s)<<"\n";
}

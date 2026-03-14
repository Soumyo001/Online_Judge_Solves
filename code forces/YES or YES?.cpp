#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        transform(s.begin(),s.end(), s.begin(), [](const unsigned char c) {return tolower(c);});
        if(
            s[0] == 'y' &&
            s[1] == 'e' &&
            s[2] == 's'
        ) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int x = 0;
    for(int i=0; i<s.length(); ) {
        if(m[s[i]] < m[s[i+1]]) {
            x += (m[s[i+1]] - m[s[i]]);
            i += 2;
        } else {
            x += m[s[i]]; ++i;
        }
    }
    return x;
}

int main(void) {
    cout<<romanToInt("IIV")<<"\n"<<romanToInt("XIIVCDMXIICCDIDID")<<"\n"<<romanToInt("MMMMCIIIIIVM")<<"\n";
}
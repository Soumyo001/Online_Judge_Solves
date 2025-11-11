#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    if(s.length() == 1) {cout<<1; return;}
    unordered_map<char, int> m;
    int mx = 0;
    int char_c = 1;
    char prev = s[0];
    ++m[s[0]];
    for(int i=0;i<s.length()-1;++i){
        if(s[i] == s[i+1]){
            mx = max(mx, ++m[s[i]]);
        }else{
            m[s[i+1]] = 1;
            mx = max(mx, m[s[i+1]]);
        }
    } 
    cout<<mx;
}

int main(void){
    solve();
}
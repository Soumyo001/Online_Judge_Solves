#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    if(s.length() == 1) return true;
    string m = "";
    for(int i=0;i<s.length();++i){
        if(isalnum(s[i])) m+=tolower(s[i]);
    }
    if(m.length() == 1 || m.length() == 0) return true;
    for(int i=0,j=m.length()-1;i<m.length()/2,j>=m.length()/2;++i,--j){
        if(m[i]!=m[j]) return false;
    }
    return true;
}

int main(void){
    string s;cin>>s;
    cout<<(isPalindrome(s) ? "true":"false");
}
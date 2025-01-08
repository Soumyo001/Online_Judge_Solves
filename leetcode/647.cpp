#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int x, int y){
    for(int i=x,j=y;i<(x+y)/2,j>=(x+y)/2;++i,--j) if(s[i]!=s[j]) return false;
    return true;
}

int maxPossiblePalindromes(string s){
    int c = 0;
    for(int i=0;i<s.length();++i){
        for(int j=i;j<s.length();++j){
            if(isPalindrome(s,i,j)) ++c;
        }
    }
    return c;
}

int main(void){
    string s;cin>>s;
    cout<<maxPossiblePalindromes(s);
}
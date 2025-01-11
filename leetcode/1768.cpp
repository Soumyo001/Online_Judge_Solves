#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    int i=1;
    string res = "";
    int x=0;
    int j=0;
    while(i<=(n+m)){
        if(i&1){
            while(j<n){
                res+=word1[j];
                ++j;
                break;
            }
        }else{
            while(x<m){
                res+=word2[x];
                ++x;
                break;
            }
        }
        ++i;
    }
    if(j!=n) while(j<n) res+=word1[j],++j;
    else if(x!=m) while(x<m) res+=word2[x],++x;
    return res;
}


int main(void){
    string s1,s2;
    cin>>s1>>s2;
    string ans = mergeAlternately(s1,s2);
    cout<<ans<<"\n";
}
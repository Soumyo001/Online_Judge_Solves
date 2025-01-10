#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int c = 0;
    int mx = INT_MIN;
    char prevC = s[0];
    char res;
    for(int i=0;i<s.length();){
        if(s[i] == prevC){
            ++c;
            ++i;
        }else{
            if(mx < c){
                mx = c;
                res = s[i-1];
            }
            c = 0;
            prevC = s[i];
        }
    }
    cout<<res;
}
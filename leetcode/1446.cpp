#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;cin>>s;
    int mx = INT_MIN;
    int c = 0;
    char prevC = s[0];
    for(int i=0;i<s.length();){
        if(s[i]==prevC){
            ++c;
            ++i;
        }else{
            mx = max(mx, c);
            c = 0;
            prevC = s[i];
        }
    }
    cout<<max(mx, c);
}
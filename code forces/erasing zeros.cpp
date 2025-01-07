#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    if(s=="0"||s=="1"){
        cout<<0<<"\n";
        return;
    }
    int c = 0;
    bool stream =false;
    int i=0,j=s.length()-1;
    while(s[i]!='1' && i<s.length()) ++i;
    while(s[j]!='1' && j>=0) --j;
    for(int x=i;x<j;++x){
        if(s[x]=='0' ) ++c;
    }
    cout<<c<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
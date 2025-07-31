#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    bool False = true;
    for(int i=0;i<n;++i){
        if(a[i]=='R' && b[i]!='R') False = false;
        if(a[i]=='G' && (b[i]!='G' && b[i]!='B')) False = false;
        if(a[i]=='B' && (b[i]!='G' && b[i]!='B')) False = false;
    }
    if(False) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
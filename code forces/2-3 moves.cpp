#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    if(n==0){
        cout<<0<<"\n";
    }else if(n%3==0)
    {
        cout<<n/3<<"\n";
        
    }else if(n%3==1)
    {
        if(n==1) cout<<2<<"\n";
        else cout<<(n/3) + 1<<"\n";
    }else if(n%3==2)
    {
        if(n==2) cout<<1<<"\n";
        else cout<<(n/3)+1<<"\n";
    }
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;cin>>n>>k;

    if(n%k==0){
        cout<<n/k<<"\n";
    }else if(n&1){
        cout<<(n/k)+(n%k)<<"\n";
    }else{
        cout<<1+((n-1)/k)+((n-1)%k)<<"\n";
    }
}


int main(void){
    int t;cin>>t;
    while(t--) solve();
}
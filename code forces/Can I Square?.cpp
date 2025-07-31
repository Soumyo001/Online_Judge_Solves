#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    long long x = 0;
    for(int i=0;i<n;++i){
        int a;cin>>a;
        x+=(1LL*a);
    }
    long long root = sqrt(x);
    if(root*root == x) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
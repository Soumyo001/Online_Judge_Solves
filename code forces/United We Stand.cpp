#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n,0);
    vector<int> b,c;
    int mn = INT_MAX;
    for(int i=0;i<n;++i) cin>>a[i], mn = min(mn,a[i]);
    for(int i=0;i<n;++i){
        if(a[i] == mn) b.push_back(a[i]);
        else c.push_back(a[i]);
    }
    
    if(b.empty() || c.empty()){
        cout<<-1<<"\n";
    }else{
        cout<<b.size()<<" "<<c.size()<<"\n";
        for(auto i:b) cout<<i<<" ";cout<<"\n";
        for(auto j:c) cout<<j<<" ";cout<<"\n";
    }
}
int main(void){
    int t;cin>>t;
    while(t--) solve();
}
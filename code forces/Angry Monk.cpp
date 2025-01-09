#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    vector<int> v(k, 0);
    for(int i=0;i<k;++i) cin>>v[i];
    sort(v.begin(),v.end());
    v.pop_back();
    int ans = 0;
    for(auto i:v) ans+=(2*i -1);
    cout<<ans<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
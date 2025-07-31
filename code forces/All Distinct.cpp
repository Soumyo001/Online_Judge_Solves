#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    set<int> s;
    for(int i=0;i<n;++i){int a;cin>>a;s.insert(a);}
    cout<<((n-s.size()) % 2 ? s.size()-1 : s.size())<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
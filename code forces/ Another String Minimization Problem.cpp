#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;++i) cin>>a[i];
    string s="";
    for(int i=0;i<m;++i) s+="B";
    for (int i = 0; i < n; ++i)
    {
        int l = a[i]-1;
        int k = m - a[i];
        if(s[min(l,k)]=='A')
            s[max(l,k)] = 'A';
        else s[min(l,k)] = 'A';
    }
    cout<<s<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
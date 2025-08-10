#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int t){
    int n;cin>>n;
    vector<vector<int>> dist(n+1, vector<int>(n+1, 0));
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>dist[i][j];
    int q;cin>>q;

    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    
    ll ans = 0;
    while(q--){
        int s, d;cin>>s>>d;
        ans+=(1LL*dist[s][d]);
    }
    cout<<"Case #"<<t<<": "<<ans<<"\n";
}

int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;++i) solve(i);
}
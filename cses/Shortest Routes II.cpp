#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void){
    int n,m,q;cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=1;i<=n;++i) dist[i][i] = 0;
    for(int i=0;i<m;++i){
        int u,v; ll wt;cin>>u>>v>>wt;
        dist[u][v] = min(dist[u][v], wt);
        dist[v][u] = min(dist[v][u], wt);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    while(q--){
        int u,v;cin>>u>>v;
        cout<<(dist[u][v] == LLONG_MAX? -1: (dist[u][v] * 1LL));
        cout<<"\n";
    }
}
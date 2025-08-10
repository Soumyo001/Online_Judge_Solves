#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int t){
    int n,r,p; cin>>n>>r>>p;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i=0;i<n;++i){
        dist[i][i] = 0;
    }
    for(int i=0;i<r;++i){
        int u,v,in,e;cin>>u>>v>>in>>e;
        dist[u][v] = (1LL*p*e-in);
    }

    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    bool neg = false;
    for(int i=0;i<n;++i){
        if(dist[i][i] < 0){
            neg = true;
            break;
        }
    }
    cout<<"Case "<<t<<": "<<(neg? "YES\n" : "NO\n");
}

int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;++i) solve(i);
}
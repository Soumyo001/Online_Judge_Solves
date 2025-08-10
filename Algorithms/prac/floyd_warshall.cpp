#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int dist[N][N];
int n,m;

int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    for(int i=0;i<m;++i){
        int u,v,wt;cin>>u>>v>>wt;
        dist[u][v] = wt;
    }

    for(int k=1; k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(dist[i][j] == INT_MAX) cout<<"I"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
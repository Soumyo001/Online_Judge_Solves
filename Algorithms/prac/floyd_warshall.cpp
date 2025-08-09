#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int graph[N][N];
int dist[N][N];
bool vis[N][N];
int n,m;
//incomplete

int main(void){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            dist[i][j] = INT_MAX;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> level(N, INT_MAX);
vector<bool> vis(N, false);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    vis[root] = true;
    level[root] = 0;
    while (!q.empty())
    {
        int v = q.front();q.pop();
        for(const auto& i : graph[v]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
                level[i] = level[v] + 1;
            }
        }
    }
    
}

int main(void){
    cin>>n>>m;
    inputGraph();
    bfs(1);
    for(int i=1;i<=n;++i) cout<<i<<": "<<level[i]<<"\n";
}
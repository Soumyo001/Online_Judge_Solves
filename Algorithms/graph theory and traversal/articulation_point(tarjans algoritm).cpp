#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
unordered_map<int, bool> vis, articulationPoint;
unordered_map<int, int> d, f, low;
int t = 0;
void inputGraph(int edges){
    for (int i = 0; i < edges; ++i)
    {
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int parent, int root){
    vis[vertex] = true;
    d[vertex] = low[vertex] = t++;
    int numberOfChildren = 0;
    for(auto& i : graph[vertex]){
        if(i == parent) continue;
        if(vis[i]){  // back edge
            low[vertex] = min(low[vertex], d[i]);
        }
        if(!vis[i]){ // tree edge
            ++numberOfChildren;
            dfs(i, vertex, root);
            low[vertex] = min(low[vertex], low[i]);
            if(d[vertex]<=low[i] && vertex!=root){
                articulationPoint[vertex] = true;
            }
        }
        if(numberOfChildren>1 && vertex == root)
            articulationPoint[vertex] = true;
    }
    f[vertex] = t++;
}

int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) d[i]=f[i]=low[i]=vis[i]=articulationPoint[i]=0;
    inputGraph(m);
    dfs(1,-1,1);
    for(int i=1;i<=n;++i) cout<<i<<" "<<articulationPoint[i]<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
vector<int> depth, height;
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int parent){
    for(auto& i: graph[vertex]){
        if(i == parent) continue;
        depth[i] = depth[vertex] + 1;
        dfs(i, vertex);
        height[vertex] = max(height[vertex], height[i] + 1);
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    depth.resize(n+1, 0);
    height.resize(n+1, 0);
    dfs(1, 0);
    for(int i=1;i<=n;++i) cout<<"For node: "<<i<<", depth: "<<depth[i]<<", height: "<<height[i]<<"\n";
}
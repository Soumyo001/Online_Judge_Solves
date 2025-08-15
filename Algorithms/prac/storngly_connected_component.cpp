#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N], rev_graph[N];
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}

void dfs(int vertex,unordered_map<int,bool>& vis,stack<int>& topSort){
    vis[vertex] = true;
    for(const auto& i:graph[vertex]) if(!vis[i]) dfs(i,vis,topSort);
    topSort.push(vertex);
}

void dfs2(int vertex, unordered_map<int,bool>& vis, unordered_map<int,vector<int>>& scc, int mark){
    vis[vertex] = true;
    scc[mark].push_back(vertex);
    for(const auto& i:rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,scc,mark);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    stack<int> topSort;
    unordered_map<int,bool> vis;
    dfs(1,vis,topSort);
    unordered_map<int,vector<int>> scc;
    int mark = 0;
    vis.clear();
    while (!topSort.empty())
    {
        int v = topSort.top();topSort.pop();
        if(!vis[v]) dfs2(v,vis,scc,++mark);
    }
    for(const auto& i:scc){
        cout<<i.first<<" -> ";
        for(auto& j:i.second) cout<<j<<" ";
        cout<<"\n";
    }
}


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> vis(N, false);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, unordered_map<int,bool>& vis, vector<int>& comp){
    vis[vertex] = true;
    comp.push_back(vertex);
    for(const auto& i:graph[vertex]) if(!vis[i]) dfs(i,vis,comp);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    unordered_map<int,bool> vis;
    vector<int> rep, comp;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            comp.clear();
            dfs(i,vis,comp);
            if(!comp.empty()) rep.push_back(comp[0]);
        }
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<rep.size()-1;++i){
        ans.push_back({rep[i],rep[i+1]});
    }
    cout<<ans.size()<<"\n";
    for(const auto& i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
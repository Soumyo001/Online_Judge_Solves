#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<bool> vis(N, false);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex){
    vis[vertex] = true;
    for(const auto& i: graph[vertex]) if(!vis[i]) dfs(i);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    int ct = 0;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            ++ct;
            dfs(i);
        }
    }
    cout<<ct<<"\n";
}
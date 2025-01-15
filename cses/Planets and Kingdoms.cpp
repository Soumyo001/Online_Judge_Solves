#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> rev_graph[N];
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}

void dfs(int vertex, unordered_map<int,bool>& vis, stack<int>& st){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,vis,st);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map<int,bool>& vis, vector<int>& id, int mark){
    id[vertex] = mark;
    vis[vertex] = true;
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,id,mark);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,vis,st);
    vis.clear();
    int mark = 0;
    vector<int> id(n+1, 0);
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]){
            dfs2(n,vis,id,++mark);
        }
    }
    cout<<mark<<"\n";
    for(int i=1;i<=n;++i) cout<<id[i]<<" ";
}
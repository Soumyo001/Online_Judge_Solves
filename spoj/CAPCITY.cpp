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

void dfs(int vertex, unordered_map<int, bool>& vis, stack<int>& st){
    vis[vertex] = true;
    for(auto& i : graph[vertex]) if(!vis[i]) dfs(i,vis,st);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map <int,bool>& vis, unordered_map <int,vector<int>>& scc, int mark){
    vis[vertex] = true;
    scc[mark].push_back(vertex);
    for(auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,scc,mark);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    unordered_map<int,bool> vis;
    stack<int> st;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,vis,st);
    int mark = 0;
    unordered_map<int,vector<int>> scc;
    vis.clear();
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]) dfs2(n,vis,scc,++mark);
    }
    for(int i=1;i<=mark;++i){
        if(scc[i].size()>1){
            cout<<scc[i].size()<<"\n";
            sort(scc[i].begin(),scc[i].end());
            for(auto& j : scc[i]) cout<<j<<" ";
            return 0;
        }
    }
    cout<<0<<"\n";
}
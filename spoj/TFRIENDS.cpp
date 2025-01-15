#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex, unordered_map<int,bool>& vis, stack<int>& st, vector<vector<int>>& graph){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,vis,st,graph);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map<int,bool>& vis, unordered_map<int,vector<int>>& scc, int mark, vector<vector<int>>& rev_graph){
    vis[vertex] = true;
    scc[mark].push_back(vertex);
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,scc,mark,rev_graph);
}

void solve(){
    int n;cin>>n;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> rev_graph(n+1);
    for(int i=1;i<=n;++i){
        string s;cin>>s;
        for(int j=0;j<s.length();++j){
            if(s[j] == 'Y'){
                graph[i].push_back(j+1);
                rev_graph[j+1].push_back(i);
            }
        }
    }
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,vis,st,graph);
    vis.clear();
    int mark = 0;
    unordered_map<int,vector<int>> scc;
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]) dfs2(n,vis,scc,++mark,rev_graph);
    }
    cout<<scc.size()<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
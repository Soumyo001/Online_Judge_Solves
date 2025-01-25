#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> makeReverseGraph(vector<vector<int>>& adj){
        vector<vector<int>> rev_graph(adj.size());
        for(int i=0;i<adj.size();++i){
            for(const auto& j : adj[i]) rev_graph[j].push_back(i);
        }
        return rev_graph;
    }
    void dfs(int vertex, stack<int>& st, unordered_map<int,bool>& vis, vector<vector<int>>& graph){
        vis[vertex] = true;
        for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,st,vis,graph);
        st.push(vertex);
    }
    void dfs2(int vertex,unordered_map<int,bool>& vis,unordered_map<int,vector<int>>& scc,int mark,vector<vector<int>>& rev_graph){
        vis[vertex] = true;
        scc[mark].push_back(vertex);
        for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,scc,mark,rev_graph);
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        vector<vector<int>> rev_graph = makeReverseGraph(adj);
        stack<int> st;
        unordered_map<int,bool> vis;
        for(int i=0;i<adj.size();++i) if(!vis[i]) dfs(i,st,vis,adj);
        vis.clear();
        int mark = 0;
        unordered_map<int,vector<int>> scc;
        while(!st.empty()){
            int n = st.top(); st.pop();
            if(!vis[n]) dfs2(n,vis,scc,++mark,rev_graph);
        }
        return mark;
    }
};

int main() {
    int t=1 ;
    // cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";
    }

    return 0;
}

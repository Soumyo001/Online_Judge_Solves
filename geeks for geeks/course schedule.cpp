#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
  stack<int> st;
  map<int,bool> vis;
  map<int,int> indeg;
  vector<vector<int>> makegraph(int n, vector<vector<int>> prerequisites){
      vector<vector<int>> graph(n);
      for(const auto& i:prerequisites){
        graph[i[1]].push_back(i[0]);
        ++indeg[i[0]];
      }
      return graph;
  }
  
  void dfs(int vertex, vector<vector<int>>& graph){
      vis[vertex] = true;
      for(auto& i:graph[vertex]) if(!vis[i]) dfs(i,graph);
      st.push(vertex);
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        for(int i=0;i<n;++i) indeg[i];
        vector<vector<int>> graph = makegraph(n, prerequisites);
        for(int i=0;i<n;++i) if(indeg[i]==0 && !vis[i]) dfs(i, graph);
        vector<int> order = {};
        while(!st.empty()){
            order.push_back(st.top());st.pop();
        }
        return (order.size()==n? order : vector<int>());
    }
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T=1;
    //cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
    }
    
    return 0;
}
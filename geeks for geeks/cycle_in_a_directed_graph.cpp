#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<int, bool> vis;
    map<int, bool> rec;
    bool dfs(int vertex, vector<vector<int>>& adj){
        vis[vertex] = true;
        rec[vertex] = true;
        bool is = false;
        for(auto& i:adj[vertex]){
            if(vis[i] && !rec[i]) continue;
            if(vis[i] && rec[i]) return true;
            is |= dfs(i,adj);
        }
        rec[vertex] = false;
        return is;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        bool is = false;
        for(int i=0;i<V;++i){
            if(!vis[i]) is |= dfs(i, adj);
        }
        return is;
    }
};

int main() {

    int t=1;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

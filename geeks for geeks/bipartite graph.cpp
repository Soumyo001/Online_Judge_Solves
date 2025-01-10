#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int vertex, int color, vector<vector<int>>& adj, map<int,int>& c){
        c[vertex] = color;
        for(auto& i:adj[vertex]){
            if(c[i]==-1) return dfs(i,!color,adj,c);
            else if(c[i]==c[vertex]) return false;
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        map<int,int> c;
        map<int, bool> vis;
        for(int i=0;i<=adj.size();++i) c[i] = -1;
        return dfs(0, 0, adj,c);
    }
};


int main() {
    int tc=1;
    // cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
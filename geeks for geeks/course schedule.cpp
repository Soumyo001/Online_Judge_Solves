#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    map<int,int> indegree;
    vector<vector<int>> makeGraph(int n, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(n);
        for(int i=0;i<n;++i) indegree[i];
        for(auto& i:prerequisites){
            graph[i[1]].push_back(i[0]);
            ++indegree[i[0]];
        }
        return graph;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> graph = makeGraph(n, prerequisites);
        queue<int> q;
        for(int i=0;i<n;++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int n = q.front();q.pop();
            order.push_back(n);
            for(const auto& i:graph[n]){
                --indegree[i];
                if(indegree[i]==0) q.push(i);
            }
        }
        return (order.size()==n?order:vector<int>());
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
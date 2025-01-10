#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	unordered_map<int, bool> vis;
	unordered_map<int, int> dis;
    unordered_map<int, int> low;
    vector<pair<int,int>> bridges;
	void dfs(int u, int par, vector<int> graph[], int t){
	    vis[u] = true;
	    dis[u]=low[u]=t++;
        int childNumber = 0;
        for(auto& v : graph[u]){
            if(v == par) continue;
            if(vis[v]){
                low[u] = min(low[u], dis[v]);
            }
            if(!vis[v]){
                ++childNumber;
                dfs(v,u,graph,t);
                low[u] = min(low[u], low[v]);
                if(dis[u]<low[v]){
                    bridges.push_back({u,v});
                }
            }
        }
        
	}
	
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        for(int i=0;i<V;++i) vis[i]=dis[i]=low[i]=0;
        int t=0;
        for(int i=0;i<V;++i){
            if(!vis[i]){
                dfs(i,-1,adj,t);
            }
        }
        for(const auto& i:bridges) if((i.first==c && i.second==d)||(i.first==d && i.second==c)) return 1;
        return 0;
    }
};

int main()
{
    int t = 1;
    // cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
    }

    return 0;
}

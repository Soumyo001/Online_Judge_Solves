#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
unordered_map<int, bool> vis;
unordered_map<int, int> d,low,parent;
vector<int> articulationPoints;
multiset<pair<int,int>> articulationBridges;
int t = 0, n, m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int u, int root){
    vis[u] = true;
    d[u] = low[u] = t++;
    int childNumber = 0;
    for(auto& v : graph[u]){
        if(v == parent[u]) continue;
        if(vis[v]){
            low[u] = min(low[u], d[v]);
        }
        else{
            parent[v] = u;
            ++childNumber;
            dfs(v, root);
            low[u] = min(low[u], low[v]);
            if(d[u] <= low[v] && u!=root){
                articulationPoints.push_back(u);
            }
            if(d[u]<low[v] && u != root){
                if(parent[u]<u) articulationBridges.insert({parent[u],u});
                else articulationBridges.insert({u,parent[u]});
                if(u<v) articulationBridges.insert({u,v});
                else articulationBridges.insert({v,u});
            }
        }
        if(childNumber > 1 && u == root){
            articulationPoints.push_back(u);
            for(auto j:graph[u]) articulationBridges.insert({u,j});
        }
    }
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<n;++i) vis[i]=d[i]=low[i]=0;
    inputGraph();
    parent[0] = -1;
    dfs(0, 0);
    cout<<articulationPoints.size()<<"\n";
    sort(articulationPoints.begin(), articulationPoints.end());
    for(const auto& i:articulationPoints) cout<<i<<" ";
    cout<<"\n"<<articulationBridges.size()<<"\n";
    for(const auto& i:articulationBridges) cout<<i.first<<" "<<i.second<<"\n";
}
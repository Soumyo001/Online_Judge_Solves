#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>> graph[N];
vector<int> dist(N, INT_MAX);
vector<bool> vis(N, false);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
    }
}

void dijkstra(){
    multiset<pair<int,int>> s;
    s.insert({0, 1});
    dist[1] = 0;
    while(!s.empty()){
        auto n = s.begin();
        int d = n->first;
        int v = n->second;
        s.erase(s.begin());
        if(vis[v]) continue;
        vis[v] = true;
        for(const auto& i: graph[v]){
            if(dist[v] + i.second < dist[i.first]){
                dist[i.first] = dist[v] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dijkstra();
    for(int i=1;i<=n;++i) cout<<i<<": "<<dist[i]<<"\n";
}
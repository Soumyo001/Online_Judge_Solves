#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int>> graph[N];
unordered_map<int, int> dist;
unordered_map<int, bool> vis;
int n,m,src;
void initGraph(){
    for(int i=0;i<m;++i) {
        int u,v,wt;cin>>u>>v>>wt;
        graph[u].push_back({v, wt});
    }
    for(int i=1;i<=n;++i) dist[i] = INT_MAX, vis[i] = false;
}
void dijkstra(int source){
    multiset<pair<int, int>> m;
    m.insert({0, source});
    dist[source] = 0;
    while(!m.empty()) {
        auto [d, n] = *m.begin();
        m.erase(m.begin());
        if(vis[n]) continue;
        vis[n] = true;
        for(const auto& i: graph[n]) {
            if(dist[i.first] > dist[n] + i.second) {
                dist[i.first] = dist[n] + i.second;
                m.insert({dist[i.first], i.first});
            }
        }
    }
}
void printDist(){
    for(int i=1;i<=n;i++) cout<<"dist from "<<src<<" to "<<i<<" is "<<dist[i]<<endl;
}
int main(void){
    cin>>n>>m>>src;
    initGraph();
    dijkstra(src);
    printDist();
}
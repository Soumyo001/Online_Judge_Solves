#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<pair<int,ll>> graph[N];
vector<ll> dist(N, LLONG_MAX);
unordered_map<int,bool> vis;
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v; ll wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt*1LL});
    }
}

void dijkstra(){
    multiset<pair<ll,int>> m;
    m.insert({0,1});
    dist[1] = 0;
    while(!m.empty()){
        auto [d, vertex] = *m.begin();
        m.erase(m.begin());
        if(vis[vertex]) continue;
        vis[vertex] = true;
        for(const auto& i:graph[vertex]){
            if(dist[i.first] > dist[vertex] + i.second){
                dist[i.first] = dist[vertex] + i.second;
                m.insert({dist[i.first], i.first});
            }
        }
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dijkstra();
    for(int i=1;i<=n;++i) cout<<dist[i]<<" ";
}
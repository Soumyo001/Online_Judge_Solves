//strategy : Shortest path in XOR metric using cycle space linear basis
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<pair<int,ll>> graph[N];
vector<ll> dist(N, LLONG_MAX);
vector<bool> vis(N, false);
vector<int> xorDist(N, 0);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v; ll wt; cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}

void dijkstra(){
    multiset<pair<ll,int>> m;
    m.insert({0, 1});
    dist[1] = 0;
    xorDist[1] = 0;
    while(!m.empty()){
        ll d = m.begin()->first;
        int node = m.begin()->second;
        m.erase(m.begin());
        if(vis[node]) continue;
        vis[node] = true;
        for(const auto& i:graph[node]){
            if(dist[node] + i.second < dist[i.first]){
                dist[i.first] = dist[node] + i.second;
                xorDist[i.first] ^= i.second;
                m.insert({dist[i.first], i.first});
            }
        }
    }
    cout<<xorDist[n]<<"\n";
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dijkstra();
}
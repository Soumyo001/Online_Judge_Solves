#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
    ll cost; int depth; int vertex;
    bool operator<(const Node& other) const {
        if (cost == other.cost) {
            if (vertex == other.vertex) {
                return depth < other.depth;
            }
            return vertex < other.vertex;
        }
        return cost < other.cost;
    }
};
const int N=3005;
const ll inf = 1e18+10;
vector<pair<int,ll>> graph[N];
bool vis[N];
ll dist[N];
int n,e;

void inputGraph(){
    for(int i=0;i<e;++i){
        int u,v; ll wt;cin>>u>>v>>wt;
        graph[u].push_back({v,wt});
        graph[v].push_back({u,wt});
    }
}

void dijkstra(int source){
    for(int i=1;i<=n;++i) 
        dist[i]=inf;
    multiset<Node> ms;
    ms.insert({0*1LL,0,source});
    dist[source]=0;
    while(!ms.empty()){
        int nd = ms.begin()->vertex;
        ll dst = ms.begin()->cost;
        int depth = ms.begin()->depth;
        ms.erase(ms.begin());
        if(vis[nd]) continue;
        vis[nd]=true;
        for(auto& i:graph[nd]){
            if(dist[i.first] > dst + (i.second*(depth+1))){
                dist[i.first] = dst + (i.second*(depth+1));
                ms.insert({dist[i.first],depth+1,i.first});
            }
        }
    }
}

void print(){
    for(int i=1;i<=n;++i){
        cout<<(dist[i]==inf ? -1:dist[i]);
        cout<<"\n";
    }
}

void solve(){
    cin>>n>>e;
    inputGraph();
    dijkstra(1);
    print();
}

int main(){
    solve();
}
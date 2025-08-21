#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> parent(N, -1);
vector<ll> dist(N, LLONG_MAX);
int n,m;

struct Node
{
    int src,dest; ll wt;
};
vector<Node> nodes;

void bellman(int source, vector<bool>& cycle_nodes){
    dist[source] = 0;
    bool flag = false;
    for(int i=0;i<n-1;++i){
        if(flag) break;
        flag = true;
        for(const auto& j:nodes){
            if(dist[j.src] != LLONG_MAX && dist[j.dest] > dist[j.src] + j.wt){
                dist[j.dest] = dist[j.src] + j.wt;
                parent[j.dest] = j.src;
                flag = false;
            }
        }
    }

    for(const auto& i:nodes){
        if(dist[i.src] != LLONG_MAX && dist[i.dest] > dist[i.src] + i.wt) cycle_nodes[i.dest] = true;
    }
}

int main(void){
    cin>>n>>m;
    nodes.resize(m);
    for(int i=0;i<m;++i) {
        cin>>nodes[i].src>>nodes[i].dest>>nodes[i].wt;
        nodes[i].wt = -nodes[i].wt; //flip weights
    }
    vector<bool> cycle_nodes(n+1, false);
    bellman(1, cycle_nodes);
    queue<int> q;
    vector<bool> vis(n+1, false);
    vector<int> g[n+1];
    for(const auto& i:nodes) g[i.src].push_back(i.dest);
    for(int i=1;i<=n;++i) if(cycle_nodes[i]) {
        q.push(i);
        vis[i] = true;
    }
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int i:g[v]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    if(vis[n]) cout<<-1<<"\n";
    else cout<<-dist[n]<<"\n";
}
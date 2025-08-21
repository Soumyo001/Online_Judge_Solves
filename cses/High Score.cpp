#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+10;
ll dist[N];
int n,m;

struct Node
{
    int src,dest; ll wt;
};
vector<Node> nodes;

int main(void){
    cin>>n>>m;
    nodes.resize(m+1);
    for(int i=0;i<m;++i){
        cin>>nodes[i].src>>nodes[i].dest>>nodes[i].wt;
        nodes[i].wt = -nodes[i].wt;
    }
    for(int i=1;i<=n;++i) dist[i] = LLONG_MAX;

    dist[1] = 0;
    bool flag = true;

    for(int i=0;i<n-1;++i){
        if(!flag) break;
        flag = false;
        for(const auto& j:nodes){
            if(dist[j.src] != LLONG_MAX && dist[j.dest] > dist[j.src] + j.wt){
                dist[j.dest] = dist[j.src] + j.wt;
                flag = true;
            }
        }
    }

    vector<int> cycle_nodes;
    for(const auto& i:nodes)
        if(dist[i.src] != LLONG_MAX && dist[i.dest] > dist[i.src] + i.wt) cycle_nodes.push_back(i.dest);
    
    vector<int> g[n+1];
    queue<int> q;
    vector<bool> vis(n+1, false);

    for(const auto& i:nodes){
        g[i.src].push_back(i.dest);
    }

    for(int i:cycle_nodes){
            q.push(i);
            vis[i] = true;
    }
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for(const auto& i:g[v]) if(!vis[i]){
            q.push(i);
            vis[i] = true;
        }
    }

    if(vis[n]) cout<<-1<<"\n";
    else cout<<-dist[n]<<"\n";
    
}
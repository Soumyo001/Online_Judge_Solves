#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N], dist[N];
int n,m;
struct Node{
    int src,dest,wt;
};
vector<Node> nodes;

vector<int> find_cycle(int v){
    for(int i=0;i<n;++i) v = parent[v];
    vector<int> res;
    int temp = v;
    res.push_back(v);
    v = parent[v];
    while(v!=temp){
        res.push_back(v);
        v = parent[v];
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<vector<int>> bellman(int source){
    bool flag = true;
    dist[source] = 0;
    for(int i=0;i<n-1;++i){
        if(!flag) break;
        flag = false;
        for(const auto& i:nodes){
            if(dist[i.src]!=INT_MAX && dist[i.dest] > dist[i.src] + i.wt){
                dist[i.dest] = dist[i.src] + i.wt;
                parent[i.dest] = i.src;
                flag = true;
            }
        }
    }
    vector<vector<int>> cycles;
    for(const auto& i:nodes){
        if(dist[i.src] != INT_MAX && dist[i.dest] > dist[i.src] + i.wt){
            cycles.push_back(find_cycle(i.dest));
        }
    }
    return cycles;
}

int main(void){
    cin>>n>>m;
    nodes.resize(m+1);
    for(int i=0;i<m;++i) cin>>nodes[i].src>>nodes[i].dest>>nodes[i].wt;
    for(int i=1;i<=n;++i) dist[i] = INT_MAX;
    const vector<vector<int>> cycles = bellman(1);
    for(const auto& i: cycles){
        for(const auto& j:i) cout<<j<<" ";
        cout<<"\n";
    }
}
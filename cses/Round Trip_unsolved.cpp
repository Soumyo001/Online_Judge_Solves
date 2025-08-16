#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> parent(N, -1);
vector<bool> vis(N, false);
int n,m,cS=-1,cE=-1;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

bool dfs(int vertex, int par){
    vis[vertex] = true;
    parent[vertex] = par;
    for(const auto& i:graph[vertex]){
        if(vis[i] && i == par) continue;
        if(vis[i]){
            cS = i;
            cE = vertex;
            return true;
        }
        if(dfs(i,vertex)) return true;
    }
    return false;
}

vector<int> find(){
    vector<int> res;
    int v = cE;
    res.push_back(cS);
    while (v!=cS)
    {
        res.push_back(v);
        v = parent[v];
    }
    res.push_back(cS);
    reverse(res.begin(), res.end());
    return res;
}

int main(void){
    cin>>n>>m;
    inputGraph();
    vector<int> path;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            cS = -1, cE = -1;
            if(dfs(i,-1) && cS != -1 && cE != -1){
                path = find();
                break;
            }
        }
    }
    if(cS == -1 || cE == -1) cout<<"IMPOSSIBLE\n";
    else{
        cout<<path.size()<<"\n";
        for(auto i:path) cout<<i<<" ";
    }
}
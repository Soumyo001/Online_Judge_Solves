#include <bits/stdc++.h>
using namespace std;
const int N  = 1e5+10;
vector<int> graph[N];
vector<int> parent(N, - 1);
unordered_map<int,bool> vis;
int n,m;
int cS = -1, cE = -1;
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
            cE = vertex;
            cS = i;
            return true;
        }
        if(dfs(i,vertex)) return true;
    }
    return false;
}

vector<int> path(){
    vector<int> res;
    res.push_back(cS);
    int v = cE;
    while(v!=cS){
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
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            if(dfs(i,-1)) break;
        }
    }
    if(cS == -1 || cE == -1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans = path();
    cout<<ans.size()<<"\n";
    for(int i:ans) cout<<i<<" ";
}
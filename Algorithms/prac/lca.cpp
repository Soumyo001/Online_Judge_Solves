#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> parent(N, 0);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int par){
    parent[vertex] = par;
    for(const auto& i : graph[vertex]) if(i!=par) dfs(i, vertex);
}

vector<int> path(int vertex){
    vector<int> path;
    while (vertex!=-1)
    {
        path.push_back(vertex);
        vertex = parent[vertex];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(void){
    int q;
    cin>>n>>m>>q;
    inputGraph();
    dfs(1,-1);
    while(q--){
        int v1, v2;cin>>v1>>v2;
        vector<int> path1 = path(v1);
        vector<int> path2 = path(v2);
        int mn = min(path1.size(), path2.size());
        int lca = -1;
        for(int i=0;i<mn;++i){
            if(path1[i] == path2[i]) lca = path1[i];
            else break;
        }
        cout<<lca<<"\n";
    }
}
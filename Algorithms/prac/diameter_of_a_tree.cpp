#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> depth(N, 0);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int parent){
    for(const auto& i: graph[vertex]){
        if(i == parent) continue;
        depth[i] = depth[vertex] + 1;
        dfs(i, vertex);
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1, 0);
    int m_vertex = -1;
    int mx = INT_MIN;
    for(int i=1;i<=n;++i){
        if(mx < depth[i]){
            mx = depth[i];
            m_vertex = i;
        }
        depth[i] = 0;
    }
    dfs(m_vertex, 0);
    for(int i=1;i<=n;++i){
        if(mx < depth[i]){
            mx = depth[i];
        }
    }
    cout<<mx;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> vis(N, false);
vector<int> color(N, -1);
bool poss = true;
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int c){
    vis[vertex] = true;
    color[vertex] = c;
    for(const auto& i : graph[vertex]){
        if(color[vertex] == color[i]) {poss=false;return;} // a bipartite graph cannot be formed if it has odd length cycle
        if(vis[i]) continue;
        dfs(i,!c);
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,0);  
    if(!poss) {cout<<"IMPOSSIBLE\n";return 0;}
    for(int i=1;i<=n;++i) cout<<color[i]+1<<" ";
}
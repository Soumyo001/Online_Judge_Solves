#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];

void inputGraph(int n){
    for(int i=1;i<=n;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int c, map<int, bool>& vis, vector<int>& color){
    vis[vertex] = true;
    ++color[c];
    for(const auto& i:graph[vertex]) if(!vis[i]) dfs(i,!c,vis,color);
}

void solve(int t){
    int n;cin>>n;
    for(int i=1;i<=N;++i) graph[i].clear();
    inputGraph(n);
    map<int, bool> vis;
    vector<int> color(2, 0);
    int ans = 0;
    for(int i=1;i<=20000;++i){
        if(!graph[i].empty() && !vis[i]){
            color[0] = color[1] = 0;
            dfs(i,0,vis,color);
            ans+= max(color[0], color[1]);
        }
    }
    cout<<"Case "<<t<<": "<<ans<<"\n";
}

int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;++i) solve(i);
}
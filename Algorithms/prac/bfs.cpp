#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
unordered_map<int, int> level;
unordered_map<int, bool> vis;
int n, m;

void inputGraph() {
    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(int source) {
    queue<int> q;
    q.push(source);
    level[source] = 0;
    vis[source] = true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(const int i: graph[v]) {
            if(!vis[i]) {
                vis[i] = true;
                level[i] = level[v] + 1;
                q.push(i);
            }
        }
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    bfs(1);
    for(int i=1;i<=n;++i) cout<<i<<": "<<level[i]<<"\n";
}
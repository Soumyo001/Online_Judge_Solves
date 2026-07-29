#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
unordered_map<int, bool> vis;
unordered_map<int, int> depth, height, parent;
int n, m;

void inputGraph() {
    for(int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int par) {
    vis[vertex] = true;
    parent[vertex] = par;
    for(const int i: graph[vertex]) {
        if(vis[i]) continue;
        depth[i] = depth[vertex] + 1;
        dfs(i, vertex);
        height[vertex] = max(height[vertex], height[i] + 1);
    }
}

int main(void) {
    cin >> n >> m;
    inputGraph();
    dfs(1, 0);
    for(int i=1; i<=n; ++i) {
        cout<<i<<" -> "<<parent[i]<<" "<<depth[i]<<" "<<height[i]<<"\n";
    }
}
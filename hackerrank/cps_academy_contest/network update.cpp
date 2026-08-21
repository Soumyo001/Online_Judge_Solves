#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
unordered_map<int, int> dist;
int n, m;


void inputGraph() {
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int mbfs(vector<int>& s) {
    queue<int> q;
    for(const int i : s) q.push(i), dist[i] = 0;
    int mx = INT_MIN;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(const int i : graph[v]) {
            if(dist.find(i) == dist.end()) {
                q.push(i);
                dist[i] = dist[v] + 1;
            }
        }   
    }
    for(int i = 1; i <= n; ++i) {
        if(dist.find(i) == dist.end()) return -1;
        mx = max(mx, dist[i]);
    }
    return mx;
}

int main() {
    cin >> n >> m;
    inputGraph();
    int roots; cin >> roots;
    vector<int> v(roots, 0);
    for(int i=0; i<roots; ++i) cin>>v[i];
    cout<<mbfs(v)<<"\n";
    
    return 0;
}

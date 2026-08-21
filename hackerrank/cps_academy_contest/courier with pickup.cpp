#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, ll>> graph[N];
int n, m;

void inputGraph() {
    for(int i = 0; i < m; ++i) {
        int u, v; ll wt; cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
}

ll dijkstra(int source, int dest, vector<bool>& vis, vector<ll>& dist) {
    multiset<pair<ll, int>> m;
    m.insert({0, source});
    dist[source] = 0;
    while(!m.empty()) {
        auto [wt, v] = *m.begin(); m.erase(m.begin());
        if(v == dest) return dist[dest];
        if(vis[v]) continue;
        vis[v] = true;
        for(const pair<int, ll>& i : graph[v]) {
            if(dist[i.first] > dist[v] + i.second) {
                dist[i.first] = dist[v] + i.second;
                m.insert({dist[i.first], i.first});
            }
        }
    }
    return -1;
}


int main() {
    cin >> n >> m;
    inputGraph();
    int s, t, k; cin >> s >> t >> k;
    vector<bool> vis(n + 1, false);
    vector<ll> dist(n + 1, LLONG_MAX);
    
    ll f = dijkstra(k, s, vis, dist);
    vis.assign(n + 1, false);
    dist.assign(n + 1, LLONG_MAX);
    ll l = dijkstra(k, t, vis, dist);
    
    if(f == -1 || l == -1) cout<<-1<<"\n";
    else cout << f + l << "\n";
    
    
    return 0;
}

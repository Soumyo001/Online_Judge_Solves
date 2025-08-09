#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int subtree_sum[N];
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int vertex, int par){
    subtree_sum[vertex] = vertex;
    for(const auto& i: graph[vertex]){
        if(i == par) continue;
        dfs(i, vertex);
        subtree_sum[vertex] += subtree_sum[i];
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    dfs(1, 0);
    ll mx = LLONG_MIN;
    for(int i=2;i<=n;++i){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        mx = max(mx, part1 * 1LL * part2);
    }
    cout<<mx<<"\n";
}
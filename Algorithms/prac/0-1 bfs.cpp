// in 0-1 bfs, a single node can be processed maximum twice
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>> graph[N];
vector<int> level(N, INT_MAX);
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back({v,0});
        graph[v].push_back({u,1});
    }
}

int bfs(int source){
    deque<int> dq;
    dq.push_back(source);
    level[source] = 0;
    while(!dq.empty()){
        int v = dq.front();dq.pop_front();
        for(const auto& i : graph[v]){
            if(level[v] + i.second < level[i.first]){
                level[i.first] = level[v] + i.second;
                if(i.second) dq.push_back(i.first);
                else dq.push_front(i.first);
            }
        }
    }
    return level[n] == INT_MAX ? -1:level[n];
}

int main(void){
    cin>>n>>m;
    inputGraph();
    cout<<bfs(1);
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=1e9+10;
vector<pair<int,int>> graph[N];
int dist[N];
int n,m,k,s,e;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back({v,1});
        graph[v].push_back({u,1});
    }
    for(int i=0;i<k;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back({v,2});
        graph[v].push_back({u,2});
    }
}
void bfs(int src){
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int node = q.front();q.pop();
        for(auto& i:graph[node]){
            if(dist[i.first]>(dist[node]+i.second)){
                q.push(i.first);
                dist[i.first]=dist[node]+i.second;
            }
        }
        
    }
}

int main(void){
    memset(dist,inf,sizeof(dist));
    cin>>n>>m>>k>>s>>e;
    inputGraph();
    bfs(s);
    cout<<(dist[e]==168430090?-1:dist[e]);
}
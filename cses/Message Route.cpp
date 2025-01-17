#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
unordered_map<int,bool> vis;
unordered_map<int,int> parent;
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(){
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    vis[1] = true;
    while(!q.empty()){
        int n = q.front();q.pop();
        for(auto& i : graph[n]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                parent[i] = n;
            }
        }
    }
}

void showNodes(){
    int v = n;
    vector<int> nodes;
    while(v!=parent[1]){
        nodes.push_back(v);
        v = parent[v];
    }
    reverse(nodes.begin(),nodes.end());
    if(nodes.size()==0 || nodes.size()==1){
        cout<<"IMPOSSIBLE\n";
    }else{
         cout<<nodes.size()<<"\n";
        for(auto i : nodes) cout<<i<<" ";
    }
}

int main(void){
    cin>>n>>m;
    inputGraph();
    bfs();
    showNodes();
}
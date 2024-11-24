#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e7+10;
vector<ll> graph[N];
bitset<N> visited;
ll pred[N+50];

void generate_tree(int branch_factor, int depth){
    ll current_node = 1;
    vector<ll> node_at_level = {current_node};
    vector<ll> next_level_nodes;
    for(int i=0;i<depth;++i){
        next_level_nodes.clear();
        for(auto& node:node_at_level){
            for(int j=0;j<branch_factor;++j){
                ++current_node;
                graph[node].push_back(current_node);
                graph[current_node].push_back(node);
                next_level_nodes.push_back(current_node);
            }
        }
        node_at_level=next_level_nodes;
    }
}

int dfs(int vertex, int parent, int goal){
    visited[vertex] = true;
    pred[vertex] = parent;
    cout<<vertex<<"\n";
    int found = -1;
    if(vertex == goal) return vertex;
    for(auto& i:graph[vertex]){
        if(!visited[i] && found==-1){
            found = dfs(i,vertex,goal);
        }
    }
    return found;
}

int main(void){

    int b,d;cin>>b>>d;
    int goal;cin>>goal;
    generate_tree(b,d);
    cout<<dfs(1,-1,goal);
}
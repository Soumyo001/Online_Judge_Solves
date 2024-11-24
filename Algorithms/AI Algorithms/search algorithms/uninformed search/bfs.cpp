#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1e7+10;
vector<ll> graph[N];
bitset<N+N> vis;
ll parent[N+N]; //long long for large search space tree where in depth, the node numbers could be millions.

void generate_tree(int branching_factor, int depth){
    ll current_node = 1;
    vector<ll> node_at_level = {current_node};
 
    vector<ll> next_level_nodes;

    for(int i=0;i<depth;++i){
        next_level_nodes.clear();
        for(auto& node:node_at_level){
            for(int j=0; j<branching_factor; ++j){
                ++current_node;
                graph[node].push_back(current_node);
                graph[current_node].push_back(node);
                next_level_nodes.push_back(current_node);
            }
        }
        node_at_level = next_level_nodes;
    }

}

void bfs(int source, int dest){
    queue<ll> q;
    q.push(source);
    parent[source] = -1;
    while(!q.empty()){
        int n = q.front();q.pop();
        cout<<n<<"\n";
        if(n==dest){
            cout<<"found\n";
            break;
        }
        for(auto& i:graph[n]){
            if(!vis[i]){
                //cout<<"reached here\n";
                vis[i]=1;
                parent[i]=n;
                q.push(i);
            }
        }
    }
}

int main(void){
    int b,d;cin>>b>>d;
    int dest;cin>>dest;
    generate_tree(b,d);
    bfs(1,dest);

}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<pair<int,int>> graph[N];
void inputGraph(int edges){
    for(int i=0;i<edges;++i){
        int u,v,cost;cin>>u>>v>>cost;
        graph[u].push_back({v,cost});
        //graph[v].push_back({u,cost});
    }
}

struct Node
{
    int id;
    int cost;

    Node(int id, int cost):id(id),cost(cost) {}
};

struct compare{
    bool operator()(const Node& a,const Node& b){
        return a.cost>b.cost;
    }
};

int ucs(int start,int goal, int nodes){
    priority_queue<Node,vector<Node>,compare> openSet;
    openSet.push(Node(start,0));

    unordered_map<int,int> parent;
    unordered_map<int,int> dist;
    parent[start] = -1;
    for(int i=1;i<=nodes;++i) dist[i]=INT_MAX;
    dist[start] = 0;

    while (!openSet.empty())
    {
        Node n = openSet.top();openSet.pop();
        if(n.id == goal){
            // for(int node = n.id; node!=-1;node=parent[node])
            //     cout<<node<<endl;
            return n.cost;
        }

        for(const auto& [neighbor, cost]:graph[n.id]){
            if(dist[neighbor] > dist[n.id] + cost){
                parent[neighbor] = n.id;
                dist[neighbor] = dist[n.id] + cost;
                openSet.push(Node(neighbor,dist[neighbor]));
            }
        }
    }
    return -1;
}

int main(void){
    int n,e;cin>>n>>e;
    inputGraph(e);
    int start,goal;cin>>start>>goal;
    cout<<ucs(start,goal,n);
}

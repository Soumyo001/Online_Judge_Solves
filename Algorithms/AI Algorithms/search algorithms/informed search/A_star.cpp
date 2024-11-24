// heuristic value of a node x : h(x) <= c(x, y)+h(y) where c(x,y) is the edge cost between node x and node y specific.


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<pair<int,double>> graph[N];
double dist[N];

void inputGraph(int edges){
    for(int i=0;i<edges;++i){
        int u,v;double cost;cin>>u>>v>>cost;
        graph[u].push_back({v,cost});
       // graph[v].push_back({u,cost});
    }
}

struct Node{
    int id;
    double g;
    double h;

    Node(int id,double g=0, double h=0) : id(id), g(g), h(h) {}

    inline double f() const { return g+h; }
};

struct compare{
    bool operator()(const Node& a, const Node& b){
        return a.f()>b.f();
    }
};

double heuristic(const int current, const int goal, const unordered_map<int,pair<int,int>>& coord){
    if(coord.find(current)!=coord.end() && coord.find(goal)!=coord.end()){
        int x1 = coord.at(current).first;
        int y1 = coord.at(current).second;
        int x2 = coord.at(goal).first;
        int y2 = coord.at(goal).second;

        return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
    }
    return 0;
}

vector<int> a_star(int start, int goal, const unordered_map<int,pair<int,int>>& coord){
    priority_queue<Node,vector<Node>,compare> openSet;
    openSet.push(Node(start,0,heuristic(start,goal,coord)));
    
    unordered_map<int,bool> visited; //referred as closedSet
    unordered_map<int,int> parent;

    dist[start] = 0.0;
    parent[start] = -1;

    while(!openSet.empty()){
        Node n = openSet.top(); openSet.pop();
        if(visited[n.id]) continue;
        visited[n.id]=true;       // use markdown (visited) after deque as same node with multiple cost can enter the queue and the A* can choose the most optimal one
        if(n.id == goal){
            vector<int> path;
            for(int node = n.id; node!=-1 ; node = parent[node])
                path.push_back(node);
            reverse(path.begin(),path.end());
            return path;
        }
        for(auto& i:graph[n.id]){
            int child = i.first;
            double cost = i.second;

            if(!visited[child] && dist[child] > dist[n.id]+cost){
                parent[child] = n.id;
                dist[child] = dist[n.id]+cost;
                double hCost = heuristic(child,goal,coord);
                openSet.push(Node(child,dist[child], hCost)); 
            }
        }
    }
    return {};
}

int main(void){
    fill_n(dist,N,INT_MAX*1.00);
    int nodes,edges;cin>>nodes>>edges;
    inputGraph(edges);
    unordered_map<int,pair<int,int>> coord;
    for(int i=1;i<=nodes;++i){
        int x,y;cin>>x>>y;
        coord[i]={x,y};
    }
    int start,goal;cin>>start>>goal;
    vector<int> path = a_star(start,goal,coord);
    for(auto& i:path){
        cout<<i<<" ";
    }
}
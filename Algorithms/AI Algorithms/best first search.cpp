#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,double>> graph[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v; double cost;cin>>u>>v>>cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }
}

struct Node{
    int id;
    double h;

    Node(int id, double h = 0.0):id(id),h(h) {}
};

struct compare{
    bool operator()(const Node& a, const Node& b){
        return a.h>b.h;
    }
};

double heuristic(const int current, const int goal, const unordered_map<int,pair<int,int>>& coord){
    if(coord.find(current)!=coord.end() && coord.find(goal)!=coord.end()){
        int x1 = coord.at(current).first;
        int y1 = coord.at(current).second;
        int x2 = coord.at(goal).first;
        int y2 = coord.at(goal).second;

        return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    }
    return 0;
}

vector<int> gbfs(int start, int goal, const unordered_map<int,pair<int,int>>& coord){
    priority_queue<Node,vector<Node>,compare> openSet;
    openSet.push(Node(start, heuristic(start,goal,coord)));

    unordered_map<int,int> parent;
    unordered_map<int,bool> visited;
    parent[start] = -1;

    while(!openSet.empty()){
        Node n = openSet.top();openSet.pop();
        
        if(n.id == goal){
            vector<int> path;
            for(int node = n.id; node!=-1; node = parent[node])
                path.push_back(node);
            reverse(path.begin(),path.end());
            return path;
        }
        visited[n.id] = true;
        for(auto& i:graph[n.id]){
            int child = i.first;
            double cost = i.second;

            if(!visited[child]) {
                parent[child] = n.id;
                openSet.push(Node(child, heuristic(child,goal,coord)));
            }      
        }
    }
    return {};
}

int main(void){
    cin>>n>>m;
    inputGraph();
    unordered_map<int,pair<int,int>> coord;
    for(int i=1;i<=n;++i) cin>>coord[i].first>>coord[i].second;
    int start,goal;cin>>start>>goal;
    vector<int> path = gbfs(start,goal,coord);
    for(auto& i:path)
        cout<<i<<" ";
}
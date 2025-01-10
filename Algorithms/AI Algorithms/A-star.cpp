#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,double>> graph[N];
double dist[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;double cost;cin>>u>>v>>cost;
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }
}

struct Node{
    int id;
    double g,h;

    Node(int id, double g = 0, double h = 0) : id(id),g(g),h(h) {}

    inline double f() const { return g+h; }
};

struct compare
{
    bool operator () (const Node& a, const Node& b){
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
    priority_queue<Node, vector<Node>, compare> openSet;
    openSet.push(Node(start,0,heuristic(start,goal,coord)));

    unordered_map<int,int> parent;
    unordered_map<int,bool> visited;

    parent[start] = -1;
    dist[start] = 0.00;

    while(!openSet.empty()){
        Node d = openSet.top(); openSet.pop();
        if(visited[d.id]) continue;
        visited[d.id] = true;
        if(d.id == goal){
            vector<int> path;
            for(int node = d.id; node != -1; node = parent[node])
                path.push_back(node);
            reverse(path.begin(),path.end());
            return path;
        }
        for(auto& i:graph[d.id]){
            int child = i.first;
            double cost = i.second;

            if(!visited[child] && dist[child] > dist[d.id] + cost){
                parent[child] = d.id;
                dist[child] = dist[d.id] + cost;
                double h = heuristic(child, goal, coord);
                openSet.push(Node(child, dist[child], h));
            }
        }
    }
    return {};
}

int main(void){
    fill_n(dist,N,INT_MAX*1.00);
    cin>>n>>m;
    inputGraph();
    unordered_map<int,pair<int,int>> coord;
    for(int i=1;i<=n;++i) cin>>coord[i].first>>coord[i].second;
    int start, goal;cin>>start>>goal;
    vector<int> path = a_star(start,goal,coord);
    for(auto& i:path){
        cout<<i<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> graph[N];
void inputGraph(int edges){
    for(int i=0;i<edges;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        //graph[v].push_back(u);
    }
}

struct Node
{
    int id;
    double h;

    Node(int id, double h) : id(id), h(h) {}
};

struct compare{
    bool operator()(const Node& a, const Node& b){
        return a.h>b.h;
    }
};

double heuristic(int current, int goal, const unordered_map<int,pair<int,int>>& coord){
    if(coord.find(current)!=coord.end() && coord.find(goal)!=coord.end()){
        int x1 = coord.at(current).first;
        int y1 = coord.at(current).second;
        int x2 = coord.at(goal).first;
        int y2 = coord.at(goal).second;
        return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
    }
    return -1;
}

int heuristic2(int current,int goal){
    return abs(goal-current);
}

vector<int> beam_search(int start, int goal, int beam_width, const unordered_map<int,pair<int,int>>& coord){
    priority_queue<Node, vector<Node>, compare> openSet;
    openSet.push(Node(start, heuristic(start,goal,coord)));

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    parent[start] = -1;

    while (!openSet.empty())
    {
        vector<Node> candidates;
        cout<<"current beam : ";
        while(!openSet.empty()){
            Node n = openSet.top();openSet.pop();

            if(visited[n.id]) continue;
            visited[n.id] = true;
            cout<<n.id<<" ";

            if(n.id == goal){
                cout<<"\n";
                vector<int> path;
                for(int node = n.id; node!=-1; node = parent[node])
                    path.push_back(node);
                reverse(path.begin(),path.end());
                return path;
            }

            for(auto& child:graph[n.id]){
                if(!visited[child]){
                    parent[child] = n.id;
                    candidates.push_back(Node(child,heuristic(child,goal,coord)));
                }
            }
        }
        cout<<"\n";
        sort(candidates.begin(),candidates.end(),[&](const Node& a,const Node& b){
            return a.h<b.h;
        });
        openSet = priority_queue<Node,vector<Node>,compare>(
            candidates.begin(),
            candidates.begin() + min((int)candidates.size(), beam_width)
        );
        // for(int i=0;i<min((int)candidates.size(),beam_width);++i)
        //     openSet.push(candidates[i]);
    }
    return {};
}

int main(void){
    int n,m;cin>>n>>m;
    inputGraph(m);
    unordered_map<int,pair<int,int>> coord;
    for(int i=1;i<=n;++i) cin>>coord[i].first>>coord[i].second;
    int start,goal, beam_width;
    cin>>start>>goal>>beam_width;

    vector<int> path = beam_search(start,goal,beam_width,coord);

    for(auto& i:path)
        cout<<i<<" ";
}
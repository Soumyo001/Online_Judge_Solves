#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7+10;
vector<int> graph[N];

void generate_tree(int branch_factor, int depth){
    int current_node = 1;
    vector<int> node_at_level = {current_node};
    vector<int> next_level_nodes;

    for(int i=0;i<depth;++i){
        next_level_nodes.clear();
        for(auto& node : node_at_level){
            for(int j=0;j<branch_factor;++j){
                ++current_node;
                graph[node].push_back(current_node);
                graph[current_node].push_back(node);
                next_level_nodes.push_back(current_node);
            }
        }
        node_at_level = next_level_nodes;
    }
}

vector<int> path(const int startSideNode, const int goalSideNode, const unordered_map<int,int>& parent_start, const unordered_map<int,int>& parent_end){

    vector<int> path;
    for(int node = startSideNode; node!=-1; node = parent_start.at(node))
        path.push_back(node);
    reverse(path.begin(),path.end());

    for(int node = goalSideNode; node!=-1; node = parent_end.at(node))
        path.push_back(node);
    
    return path;
}

vector<int> bidirectional_search(int start, int goal){
    queue<int> start_q, end_q;
    start_q.push(start);
    end_q.push(goal);
    unordered_map<int, bool> visit_start, visit_end;
    unordered_map<int, int> parent_start, parent_end;
    visit_start[start] = true;
    visit_end[goal] = true;
    parent_start[start] = -1;
    parent_end[goal] = -1;
    
    while (!start_q.empty() && !end_q.empty())
    {
        int n_s = start_q.front(); start_q.pop();

        for(auto& i:graph[n_s]){
            if(visit_end[i]){
                return path(n_s,i,parent_start,parent_end);
            }

            if(!visit_start[i]){
                visit_start[i] = true;
                parent_start[i] = n_s;
                start_q.push(i);
            }
        }

        int n_e = end_q.front(); end_q.pop();

        for(auto& i:graph[n_e]){
            if(visit_start[i]){
                return path(i,n_e,parent_start,parent_end);
            }

            if(!visit_end[i]){
                visit_end[i] = true;
                parent_end[i] = n_e;
                end_q.push(i);
            }
        }
    }
    return {};
}

int main(){
    int b,d; cin>>b>>d;
    int goal; cin>>goal;

    generate_tree(b,d);

    vector<int> path = bidirectional_search(1, goal);

    for(auto& i:path)
        cout<<i<<" ";
}
#include <bits/stdc++.h>
using namespace std;

bool topSortKahn(vector<vector<int>>& graph, unordered_map<int,int>& indeg){
    queue<int> q;
    for(const pair<int,int>& i:indeg) if(i.second == 0) q.push(i.first);
    int count = 0;
    int sz = graph.size();
    while(!q.empty()){
        int n = q.front();q.pop();
        ++count;
        for(const int& i:graph[n]) if(!--indeg[i]) q.push(i);
    }
    return count == sz;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, int> indeg;
    for(int i=0;i<numCourses;++i) indeg[i] = 0;
    vector<vector<int>> graph(numCourses);
    for(const vector<int>& i: prerequisites){
        graph[i[1]].push_back(i[0]);
        ++indeg[i[0]];
    }

    return topSortKahn(graph, indeg);
}

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<int>> prereq;
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        prereq.push_back({u, v});
    }
    cout<<canFinish(n, prereq);
}
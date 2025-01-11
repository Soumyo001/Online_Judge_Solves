#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> makeGraph(int n, vector<int>& cost){
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<n;++i){
        if(i == n-1){
            graph[i].push_back({0,cost[i]});
        }
        else graph[i].push_back({i+1,cost[i]});
    }
    return graph;
}
int bfs(int root, vector<vector<pair<int,int>>>& graph, vector<bool>& vis, vector<int>& gas){
    queue<pair<int,int>> q;
    q.push({root, gas[root]});
    while(!q.empty()){
        pair<int, int> n = q.front();q.pop();
        int node = n.first;
        int g = n.second;
        // cout<<node<<" "<<g<<"\n";
        if(node == root && g > 0 && vis[node]) return 1;
        for(const auto& i:graph[node]){
            if(!vis[i.first]){
                vis[i.first] = true;
                int c = g-i.second+gas[i.first];
                // cout<<i.first<<" "<<i.second<<" "<<c<<"\n";
                if(g >= i.second)
                    q.push({i.first, c});
                else return 0;
            }
        }
    }
    return 0;
}

int solve(vector<int>& gas, vector<int>& cost){
    int n = gas.size();
    if(n == 1 && gas[0]>=cost[0]) return 0;
    else if(n == 1) return -1;
    long long gSum = 0, cSum = 0;
    for(int i=0;i<gas.size();++i) gSum+=gas[i];
    for(int i=0;i<cost.size();++i) cSum+=cost[i];
    if(gSum<cSum) return -1;
    vector<vector<pair<int,int>>> graph = makeGraph(n,cost);
    int ans = -1;
    for(int i=0;i<n;++i){
        vector<bool> vis(n, false);
        // cout<<"\n\n"<<i<<"\n";
        if(gas[i]>cost[i] && bfs(i,graph,vis,gas) == 1){
            ans = i;
            break;
        }
    }
    return ans;
}

int solve2(vector<int>& gas, vector<int>& cost){
    long long tot_gas = 0, tot_cost = 0;
    int start_idx = 0, current_gas = 0;
    for(int i=0;i<gas.size();++i){
        tot_gas+=gas[i];
        tot_cost+=cost[i];
        current_gas+=(gas[i]-cost[i]);
        if(current_gas<0){
            start_idx = i+1;
            current_gas = 0;
        }
    }
    return (tot_gas<tot_cost ? -1 : start_idx);
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    return solve2(gas, cost);
}

int main(void){
    int n;cin>>n;
    vector<int> cost(n, 0);
    vector<int> gas(n, 0);
    for(int i=0;i<n;++i) cin>>gas[i];
    for(int i=0;i<n;++i) cin>>cost[i];
    cout<<canCompleteCircuit(gas,cost);
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> rev_graph[N];
vector<int> cond_graph[N];
int n,m;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}

void dfs(int vertex, unordered_map<int, bool>& vis, stack<int>& st){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,vis,st);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map<int, bool>& vis, int mark, vector<int>& sccid, unordered_map<int,ll>& sccCost, vector<int>& coins){
    sccCost[mark]+= coins[vertex];
    vis[vertex] = true;
    sccid[vertex] = mark;
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,mark,sccid,sccCost,coins);
}

ll maxCoins(unordered_map<int,int>& indegree, const unordered_map<int,ll>& sccCost, int mark){
    queue<int> q;
    vector<ll> dp(n+1, 0);
    ll max_coins = 0;
    for(int i=1;i<=mark;++i) if(indegree[i] == 0) q.push(i),dp[i] = sccCost.at(i);
    while(!q.empty()){
        int u = q.front();q.pop();
        max_coins = max(max_coins, dp[u]);
        for(const auto& v : cond_graph[u]){
            --indegree[v];
            dp[v] = max(dp[v], dp[u] + sccCost.at(v));
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }
    return max_coins;
}

int main(void){
    cin>>n>>m;
    vector<int> coins(n+1, 0);
    for(int i=1;i<=n;++i) cin>>coins[i];
    inputGraph();
    unordered_map<int, bool> vis;
    stack<int> st;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,vis,st);
    vis.clear();
    int mark = 0;
    unordered_map<int,ll> sccCost;
    vector<int> sccid(n+1, 0);
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]) dfs2(n,vis,++mark,sccid,sccCost,coins);
    }
    vis.clear();
    unordered_map<int,int> indegree;
    for(int i=1;i<=n;++i){
        for(const auto& j : graph[i]){
            if(sccid[i]!=sccid[j] ){
                cond_graph[sccid[i]].push_back(sccid[j]);
                ++indegree[sccid[j]];
            }
        }
    }
    cout<<maxCoins(indegree,sccCost,mark);
}
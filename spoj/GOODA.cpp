#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+10;
vector<int> graph[N];
vector<int> rev_graph[N];
vector<int> cond_graph[N];
int n,m,s,e;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}
void dfs(int vertex, unordered_map<int,bool>& vis, stack<int>& st){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,vis,st);
    st.push(vertex);
}
void dfs2(int vertex, unordered_map<int,bool>& vis, vector<int>& sccid, unordered_map<int,ll>& sccCost, int mark, vector<int>& fun){
    vis[vertex] = true;
    sccid[vertex] = mark;
    sccCost[mark] += fun[vertex];
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,sccid,sccCost,mark,fun);
}
ll maxFun(vector<int>& indegree, unordered_map<int,bool>& vis, unordered_map<int,ll>& sccCost, int mark, vector<int>& sccid){
    queue<int> q;
    q.push(sccid[s]);
    vector<ll> dp(mark+1, 0);
    dp[sccid[s]] = sccCost[sccid[s]];
    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = true;
        for(const auto& v : cond_graph[u]){
            if(!vis[v] && dp[v] < dp[u] + sccCost[v]){
                dp[v] = dp[u] + sccCost[v];
                q.push(v);
            }
        }
    }
    return dp[sccid[e]];
}
int main(void){
    cin>>n>>m>>s>>e;
    vector<int> fun(n+1,0);
    for(int i=1;i<=n;++i) cin>>fun[i];
    inputGraph();
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,vis,st);
    vis.clear();
    vector<int> sccid(n+1,0);
    unordered_map<int,ll> sccCost;
    int mark = 0;
    while (!st.empty())
    {
        int n = st.top();st.pop();
        if(!vis[n]) dfs2(n,vis,sccid,sccCost,++mark,fun);
    }
    vis.clear();
    vector<int> indegree(mark+1, 0);
    for(int i=1;i<=n;++i){
        for(const auto& j : graph[i]){
            if(sccid[i]!=sccid[j]){
                cond_graph[sccid[i]].push_back(sccid[j]);
                ++indegree[sccid[j]];
            }
        }
    }
    cout<<maxFun(indegree,vis,sccCost,mark,sccid);
}
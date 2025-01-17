#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+7;
vector<int> graph[N];
vector<int> rev_graph[N];
int n,m;

void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
}

void dfs(int vertex, stack<int>& st, unordered_map<int,bool>& vis){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,st,vis);
    st.push(vertex);
}

void scc(int vertex, unordered_map<int,bool>& vis, unordered_map<int,int>& freq, ll& mx,vector<int>& cost){
    vis[vertex] = true;
    mx = min(mx, 1LL*cost[vertex]);
    ++freq[cost[vertex]];
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) scc(i,vis,freq,mx,cost);
}

int main(void){
    cin>>n;
    vector<int> cost(n+1,0);
    for(int i=1;i<=n;++i) cin>>cost[i];
    cin>>m;
    inputGraph();
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,st,vis);
    vis.clear();
    ll tot = 0;
    ll ways = 1;
    ll mx = INT_MAX;
    unordered_map<int,int> freq;
    while(!st.empty()){
        int n = st.top();st.pop();
        mx = LLONG_MAX;
        freq.clear();
        if(!vis[n]) {
            scc(n,vis,freq,mx,cost);
            tot+=mx;
            ways*=(freq[mx]);
        }

    }
    cout<<tot<<" "<<ways%mod;
}
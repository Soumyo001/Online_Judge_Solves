#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
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

void dfs(int vertex, unordered_map<int,bool>& vis, stack<int>& st){
    vis[vertex] = true;
    for(auto& i:graph[vertex]) if(!vis[i]) dfs(i,vis,st);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map<int,bool>& vis){
    vis[vertex] = true;
    for(auto& i:rev_graph[vertex]) if(!vis[i]) dfs2(i,vis);
}

int main(void){
    cin>>n>>m;
    inputGraph();
    vector<int> ans;
    unordered_map<int,bool> vis;
    stack<int> st;
    for(int i=1;i<=n;++i)if(!vis[i])dfs(i,vis,st);
    vis.clear();
    ans.clear();
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]){
            ans.push_back(n);
            dfs2(n,vis);
        }
    }
    if(ans.size()==1) cout<<"YES\n";
    else{
        cout<<"NO\n";
        cout<<ans[1]<<" "<<ans[0]<<"\n";
    }
}
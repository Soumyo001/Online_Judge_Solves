#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
vector<int> rev_graph[N];
int n;
struct LEGO
{
    ll x1,y1,x2,y2;
};

void makeGraph(vector<LEGO>& cords){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i!=j && cords[i].y2 == cords[j].y1 && cords[i].x2 > cords[j].x1){
                graph[i].push_back(j);
                rev_graph[j].push_back(i);
            }
        }
    }
}

void dfs(int vertex, stack<int>& st, unordered_map<int,bool>& vis){
    vis[vertex] = true;
    for(const auto& i : graph[vertex]) if(!vis[i]) dfs(i,st,vis);
    st.push(vertex);
}

void dfs2(int vertex, unordered_map<int,bool>& vis, int mark, unordered_map<int,vector<int>>& scc){
    scc[mark].push_back(vertex);
    vis[vertex] = true;
    for(const auto& i : rev_graph[vertex]) if(!vis[i]) dfs2(i,vis,mark,scc);
}

int main(void){
    cin>>n;
    vector<LEGO> cords(n+1);
    for(int i=1;i<=n;++i){
        ll x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        cords[i] = {x1,y1,x2,y2};
    }
    makeGraph(cords);
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,st,vis);
    vis.clear();
    int mark = 0;
    unordered_map<int,vector<int>> scc;
    while(!st.empty()){
        int n = st.top();st.pop();
        if(!vis[n]) {
            dfs2(n,vis,++mark,scc);
        }
    }
    cout<<mark<<endl;
}
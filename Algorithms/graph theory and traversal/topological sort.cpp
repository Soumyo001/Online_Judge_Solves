#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
unordered_map<int,int> indegree,dis,f;
unordered_map<int,bool> vis;
stack<int> st;
int n,m,t=0;
void inputGraph(){
    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        graph[u].push_back(v);
        ++indegree[v];
    }
}

void topSort(int vertex){
    vis[vertex] = true;
    dis[vertex] = t++;
    for(const auto& i : graph[vertex]){
        if(vis[i]) continue;
        topSort(i);
    }
    f[vertex] = t++;
    st.push(vertex);
}

void topSort2(){
    queue<int> q;
    int processed_nodes = 0;
    for(int i=1;i<=n;++i) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int n = q.front();q.pop();
        ++processed_nodes;
        cout<<n<<" ";
        for(const auto& i : graph[n]){
            --indegree[i];
            if(indegree[i] == 0) q.push(i);
        }
    }
    if(processed_nodes!=n){
        cerr<<"The Graph Contains Cycle.\n";
    }
}

void topSortDFSWithFinishingTimes(){
    for(int i=1;i<=n;++i) vis[i] = false;
    for(int i=1;i<=n;++i) if(!vis[i]) topSort(i);
    vector<pair<int,int>> v(f.begin(),f.end());
    sort(v.begin(),v.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        return a.second > b.second;
    });
    for(auto& i:v) cout<<i.first<<" "<<i.second<<"\n";
    cout<<"\n";
}

void topSortDFSWithStack(){
    for(int i=1;i<=n;++i) if(!vis[i]) topSort(i);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main(void){
    cin>>n>>m;
    inputGraph();
    topSortDFSWithStack();
    topSort2();
    topSortDFSWithFinishingTimes();
}
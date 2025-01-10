#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
vector<ll> graph[N];
map<ll,ll> indegree;
vector<int> order;
int n,m,s;

void inputGraph(){
    for(int i=0;i<m;++i){
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        ++indegree[v];
    }
}

vector<double> topSort(){
    queue<ll> q;
    vector<double> prob(n+1, 0.0);
    prob[s] = 1.0;
    for(int i=1;i<=n;++i) if(indegree[i]==0) q.push(i);
    while (!q.empty())
    {
        ll n = q.front();
        q.pop();
        if(graph[n].empty()) continue;
        double splitProb = prob[n]/graph[n].size();
        for(auto& i:graph[n]){
            prob[i]+=splitProb;
            --indegree[i];
            if(indegree[i]==0)
                q.push(i);
        }
    }
    return prob;
}
int main(void){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    inputGraph();
    vector<double> prob = topSort();
    double maxProb = 0.0;
    for(int i=1;i<=n;++i) if(graph[i].empty()) maxProb = max(maxProb,prob[i]);
    for(int i=1;i<=n;++i) if(graph[i].empty() && abs(maxProb-prob[i]<1e-9)) order.push_back(i);
    for(auto& i:order) cout<<i<<" ";
}
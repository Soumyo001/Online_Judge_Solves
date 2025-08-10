#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N], sz[N];

void make(int i){
    parent[i] = i;
    sz[i] = 1;
}

int find(int i){
    return (parent[i] == i? i : parent[i] = find(parent[i]));
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b]; 
    }
}

int main(void){
    int n,m;cin>>n>>m;
    multiset<pair<int, pair<int,int>>> s;
    for(int i=1;i<=n;++i) make(i);
    for(int i=0;i<m;++i){
        int u,v,wt;cin>>u>>v>>wt;
        s.insert({wt,{u,v}});
    }
    int tot_wt = 0;
    for(const auto& i:s){
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;
        if(find(u) == find(v)) continue;
        Union(u,v);
        tot_wt += wt;
        cout<<u<<" "<<v<<"\n";
    }
    cout<<tot_wt<<"\n";
}
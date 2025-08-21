#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
vector<ll> dist(N, LLONG_MAX);
vector<int> parent(N, -1);
int n,m;

struct Node
{
    int src, dest; ll wt;
};
vector<Node> nodes;

vector<int> find_cycle(int v){
    for(int i=0;i<n-1;++i) v = parent[v];
    vector<int> res;
    int temp = v;
    res.push_back(v);
    v = parent[v];
    while (v!= temp)
    {
        res.push_back(v);
        v = parent[v];
    }
    res.push_back(temp);
    reverse(res.begin(), res.end());
    return res;
}

void bellman(){

    dist[nodes.begin()->src] = 0;
    bool flag = false;
    for(int i=0;i<n-1;++i){
        if(flag) break;
        flag = true;
        for(const auto& j:nodes){
            if(dist[j.src] != LLONG_MAX && dist[j.dest] > dist[j.src] + j.wt){
                dist[j.dest] = dist[j.src] + j.wt;
                parent[j.dest] = j.src;
                flag = false;
            }else if(dist[j.src] == LLONG_MAX && dist[j.dest] == LLONG_MAX) {
                dist[j.src] = 0;
                dist[j.dest] = dist[j.src] + j.wt;
            }
        }
    }

    int cN = -1;
    for(const auto& i:nodes){
        if(dist[i.src] != LLONG_MAX && dist[i.dest] > dist[i.src] + i.wt){
            cN = i.dest;
        }
    }
    if(cN == -1) cout<<"NO\n";
    else{
        cout<<"YES\n";
        vector<int> cycle = find_cycle(cN);
        for(int i:cycle) cout<<i<<" ";
    }
}

int main(void){
    cin>>n>>m;
    nodes.resize(m);
    int sN = -1;
    for(int i=0;i<m;++i){
        cin>>nodes[i].src>>nodes[i].dest>>nodes[i].wt;
        if(nodes[i].src == nodes[i].dest && nodes[i].wt < 0){
            sN = nodes[i].src;
        }
    }
    if(sN != -1) cout<<"YES\n"<<sN<<" "<<sN<<"\n";
    else bellman();
}
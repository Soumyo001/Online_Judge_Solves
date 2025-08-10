#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N], sz[N];

void make(int i){
    parent[i]=i;
    sz[i]=1;
}

int find(int i){
    return (i == parent[i] ? i : parent[i] = find(parent[i]));
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
    int n;cin>>n;
    int q;cin>>q;
    for(int i=1;i<=n;++i) make(i);
    while(q--){
        int op;cin>>op;
        if(op == 1){
            int x;cin>>x;
            cout<<find(x)<<"\n";
        }else if(op == 2){
            int a,b;cin>>a>>b;
            Union(a,b);
        }else ++q;
    }
}
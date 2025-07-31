#include <bits/stdc++.h>
using namespace std;

void build_tree(int l, int r, vector<vector<int>>& tree, vector<int>& v, vector<int>& d, int depth){
    if(l>r) return;
    if(l == r){
        d[l] = depth;
        return;
    }
    int mx = INT_MIN;
    int idx = -1;
    for(int i=l;i<=r;++i){
        if(mx<v[i]){
            mx = v[i];
            idx = i;
        }
    }
    d[idx] = depth;
    // cout<<v[idx]<<"\n";
    build_tree(l,idx-1,tree,v,d,depth+1);
    build_tree(idx+1,r,tree,v,d,depth+1);
}

void solve(){
    int n;cin>>n;
    vector<int> v(n,0);
    vector<int> d(n,0);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<vector<int>> tree(n+1);
    build_tree(0,n-1,tree,v,d,0);
    for(int i=0;i<n;++i) cout<<d[i]<<" ";cout<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
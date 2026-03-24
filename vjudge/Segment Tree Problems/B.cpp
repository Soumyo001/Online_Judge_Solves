#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(int n): n(n),tree(n*4, 0) { }
    void build(int node,int b,int e,vector<int>& arr) {
        if(b == e) {
            tree[node]=arr[b];
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=min(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int idx,int x) {
        if(e<idx || idx<b) return;
        if(b>=idx && e<=idx) {
            tree[node]=x;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,idx,x);
        update(right,mid+1,e,idx,x);
        tree[node]=min(tree[left],tree[right]);
    }
    int query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return INT_MAX;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        int p1=query(left,b,mid,i,j);
        int p2=query(right,mid+1,e,i,j);
        return min(p1,p2);
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<int> v(n+1);
    SegmentTree seg(n);
    for(int i=1;i<=n;++i) cin>>v[i];
    seg.build(1,1,n,v);
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int k,u;cin>>k>>u;
            seg.update(1,1,n,k,u);
            v[k]=u;
        } else {
            int a,b;cin>>a>>b;
            cout<<seg.query(1,1,n,a,b)<<"\n";
        }
    }
}
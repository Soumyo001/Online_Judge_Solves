#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
    int initiate(int x) { return x; }
    int merge(const int a, const int b) { return max(a, b); }
public:
    SegmentTree(int n): n(n),tree(n*4, 0) { }
    void build(int node,int b,int e,vector<int>& arr) {
        if(b == e) {
            tree[node]=initiate(arr[b]);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=merge(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int i,int j,int x) {
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]+=x;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node]=merge(tree[left],tree[right]);
    }
    int query(int node,int b,int e,int x) {
        if(tree[node]<x) return 0;
        if(b == e) return b;
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        if(tree[left]>=x) return query(left,b,mid,x);
        else return query(right,mid+1,e,x); 
    }
};

int main(void) {
    int n,m; cin >> n >> m;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i) cin >> v[i];
    SegmentTree seg(n);
    seg.build(1,1,n,v);
    while(m--) {
        int x; cin >> x;
        int idx = seg.query(1,1,n,x);
        seg.update(1,1,n,idx,idx,-x);
        cout<<idx<<" ";
    }
}
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
    int merge(const int a,const int b) { return a+b; }
public:
    SegmentTree(int n): n(n), tree(n*4,0) { }
    void build(int node,int b,int e) {
        if(b == e) {
            tree[node]=1;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid);
        build(right,mid+1,e);
        tree[node]=merge(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=0;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j);
        update(right,mid+1,e,i,j);
        tree[node]=merge(tree[left],tree[right]);
    }
    int query(int node,int b,int e,int k) {
        if(b == e) return b;
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        if(tree[left]>=k) return query(left,b,mid,k);
        else return query(right,mid+1,e,k-tree[left]);
    }
};

int main(void) {
    int n; cin>>n;
    SegmentTree seg(n);
    seg.build(1,1,n);
    vector<int> v(n+1);
    for(int i=1;i<=n;++i) cin >> v[i];
    for(int i=1;i<=n;++i) {
        int x; cin >> x;
        int idx = seg.query(1,1,n,x);
        seg.update(1,1,n,idx,idx);
        cout<<v[idx]<<" ";
    }
}
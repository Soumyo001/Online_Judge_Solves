#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(int n): n(n),tree(n*4) { }
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
        if(b<idx || idx<e) return;
        if(b>=idx && e<=idx) {
            tree[node]+=x;
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
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    SegmentTree seg(n);
    seg.build(1,0,n-1,v);
    int q;cin>>q;
    while(q--) {
        int i,j;cin>>i>>j;
        cout<<seg.query(1,0,n-1,i,j)<<"\n";
    }
}
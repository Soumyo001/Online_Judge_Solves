#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum=0,pref=0,suff=0,best=0;
};
class SegmentTree {
private:
    int n;
    vector<Node> tree;
    Node initiate(int x) { return {x,x,x,x}; }
    Node merge(const Node& a,const Node& b) {
        if(a.sum==INT_MIN) return b;
        if(b.sum==INT_MIN) return a;
        Node res;
        res.sum=a.sum+b.sum;
        res.pref=max(a.pref,a.sum+b.pref);
        res.suff=max(b.suff,b.sum+a.suff);
        res.best=max({a.best,b.best,a.suff+b.pref});
        return res;
    }
public:
    SegmentTree(int n): n(n),tree(n*4) { }
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
    void update(int node,int b,int e,int i,int j,int x) { //leaf update
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=initiate((e-b+1)*x);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node]=merge(tree[left],tree[right]);
    }
    Node query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return {INT_MIN,INT_MIN,INT_MIN,INT_MIN};
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        Node p1=query(left,b,mid,i,j);
        Node p2=query(right,mid+1,e,i,j);
        return merge(p1,p2);
    }
};

int main(void) {
    int n;cin>>n;vector<int> v(n+1);for(int i=1;i<=n;++i) cin>>v[i];
    SegmentTree seg(n);
    seg.build(1,1,n,v);
    int q;cin>>q;
    while(q--) {
        int op;cin>>op;
        if(op == 0) {
            int idx,x;cin>>idx>>x;
            seg.update(1,1,n,idx,idx,x);
        } else {
            int i,j;cin>>i>>j;
            Node ans=seg.query(1,1,n,i,j);
            cout<<ans.best<<"\n";
        }
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    ll sum=0,pref=0,suff=0,best=0;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;
    Node initiate(ll x) {
        if(x < 0) return {x,0,0,0}; //when empty subarray is allowed
        return {x,x,x,x};
    }
    Node merge(const Node& a,const Node& b) {
        if(a.sum == LLONG_MIN) return b;
        if(b.sum == LLONG_MIN) return a;
        Node res;
        res.sum=a.sum+b.sum;
        res.pref=max(a.pref,a.sum+b.pref);
        res.suff=max(b.suff,b.sum+a.suff);
        res.best=max({a.best,b.best,a.suff+b.pref});
        return res;
    }
public:
    SegmentTree(int n): n(n), tree(n*4) { }
    void build(int node,int b,int e,vector<ll>& arr) {
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
    void update(int node,int b,int e,int idx,ll x) {
        if(e<idx || idx<b) return;
        if(b>=idx && e<=idx) {
            tree[node]=initiate(x);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,idx,x);
        update(right,mid+1,e,idx,x);
        tree[node]=merge(tree[left],tree[right]);
    }
    Node query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return {LLONG_MIN,LLONG_MIN,LLONG_MIN,LLONG_MIN};
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
    int n,q;cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i];
    SegmentTree seg(n);
    seg.build(1,1,n,v);
    while(q--) {
        int a;ll b;cin>>a>>b;
        seg.update(1,1,n,a,b);
        cout<<seg.query(1,1,n,1,n).best<<"\n";
    }
}
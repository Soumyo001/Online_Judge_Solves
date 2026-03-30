#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazyAdd, lazySet;
    void push(int node,int b,int e) {
        if(lazySet[node]!=-1) {
            tree[node]=((e-b+1)*lazySet[node]);
            if(b!=e) {
                lazySet[(node<<1)]=lazySet[node];
                lazySet[(node<<1)+1]=lazySet[node];
                lazyAdd[(node<<1)]=0;
                lazyAdd[(node<<1)+1]=0;
            }
            lazySet[node]=-1;
        }
        if(lazyAdd[node]!=0) {
            tree[node]+=((e-b+1)*lazyAdd[node]);
            if(b!=e) {
                lazyAdd[(node<<1)]+=lazyAdd[node];
                lazyAdd[(node<<1)+1]+=lazyAdd[node];
            }
            lazyAdd[node]=0;
        }
    }
public:
    SegmentTree(int n): n(n),tree(n*4,0),lazyAdd(n*4,0),lazySet(n*4,-1) { }
    void build(int node,int b,int e,vector<ll>& arr) {
        if(b == e) {
            tree[node]=arr[b];
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=tree[left]+tree[right];
    }
    void updateAdd(int node,int b,int e,int i,int j,ll x) {
        push(node,b,e);
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            lazyAdd[node]+=x;
            push(node,b,e);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        updateAdd(left,b,mid,i,j,x);
        updateAdd(right,mid+1,e,i,j,x);
        tree[node]=tree[left]+tree[right];
    }
    void updateSet(int node,int b,int e,int i,int j,ll x) {
        push(node,b,e);
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            lazySet[node]=x;
            lazyAdd[node]=0;
            push(node,b,e);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        updateSet(left,b,mid,i,j,x);
        updateSet(right,mid+1,e,i,j,x);
        tree[node]=tree[left]+tree[right];
    }
    ll query(int node,int b,int e,int i,int j) {
        push(node,b,e);
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        ll p1=query(left,b,mid,i,j);
        ll p2=query(right,mid+1,e,i,j);
        return p1+p2;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    SegmentTree seg(n);
    seg.build(1,0,n-1,v);
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int a,b;ll x;cin>>a>>b>>x;
            seg.updateAdd(1,0,n-1,a-1,b-1,x);
        } else if(op == 2) {
            int a,b;ll x;cin>>a>>b>>x;
            seg.updateSet(1,0,n-1,a-1,b-1,x);
        } else {
            int a,b;cin>>a>>b;
            cout<<seg.query(1,0,n-1,a-1,b-1)<<"\n";
        }
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazy;
public:
    SegmentTree(int n): n(n),tree(n*4,0),lazy(n*4,-1) { }
    void build(int node,int b,int e,vector<ll>& arr) {
        if(b == e) {
            tree[node]=arr[b];
            return;
        }
        int mid=(b+e)>>1;
        int left(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=tree[left]+tree[right];
    }
    void update(int node,int b,int e,int i,int j,ll x) {
        if(lazy[node]!=-1) {
            tree[node]=((e-b+1)*lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }
            lazy[node]=-1;
        }
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=((e-b+1)*x);
            if(b!=e) {
                lazy[(node<<1)]=x;
                lazy[(node<<1)+1]=x;
            }
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node]=tree[left]+tree[right];
    }
    ll query(int node,int b,int e,int i,int j) {
        if(lazy[node]!=-1) {
            tree[node]=((e-b+1)*lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }
            lazy[node]=-1;
        }
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
            int i,j;ll x;cin>>i>>j>>x;
            seg.update(1,0,n-1,i-1,j-1,x);
        } else {
            int i,j;cin>>i>>j;
            cout<<seg.query(1,0,n-1,i-1,j-1)<<"\n";
        }
    }
}
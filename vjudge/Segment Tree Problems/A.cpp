#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
public:
    SegmentTree(int n): n(n),tree(n*4, 0) { }
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
    void update(int node,int b,int e,int idx,ll x) {
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
        tree[node]=tree[left]+tree[right];
    }
    ll query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        ll p=query(left,b,mid,i,j);
        ll q=query(right,mid+1,e,i,j);
        return p+q;
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
            int k;ll u;cin>>k>>u;
            seg.update(1,0,n-1,k-1,u);
        } else {
            int a,b;cin>>a>>b;
            cout<<seg.query(1,0,n-1,a-1,b-1)<<"\n";
        }
    }
}
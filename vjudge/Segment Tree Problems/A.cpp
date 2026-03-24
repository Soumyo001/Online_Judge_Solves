#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree;
public:
    SegmentTree(int n): n(n),tree(n*4,0) { }
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
        update(right,idx+1,e,idx,x);
        tree[node]=tree[left]+tree[right];
    }
    ll query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        ll p1=query(left,b,mid,i,j);
        ll p2=query(right,mid+1,e,i,j);
        return (p1)+(p2);
    }
};

class BIT {
private:
    int n;
    vector<ll> bit;
public:
    BIT(int n): n(n),bit(n+1,0) { }
    void update(int idx, ll x) {
        while(idx <= n) {
            bit[idx]+=x;
            idx = idx + (idx & -idx);
        }
    }
    ll sum(int idx) {
        ll res=0;
        while(idx > 0) {
            res+=bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    BIT bit(n);
    vector<ll>v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i],bit.update(i,v[i]);
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int k;ll u;cin>>k>>u;
            bit.update(k,u-v[k]);
            v[k]=u;
        } else {
            int a,b;cin>>a>>b;
            cout<<bit.sum(b)-bit.sum(a-1)<<"\n";
        }
    }
}
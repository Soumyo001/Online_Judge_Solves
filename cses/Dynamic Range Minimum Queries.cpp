#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazy;
    ll initiate(ll x) { return x; }
    ll merge(ll a,ll b) { return min(a,b); }
public:
    SegmentTree(int n): n(n), tree(n*4, INT_MAX), lazy(n*4, -1) { }
    void init(int node,int b,int e,vector<ll>& arr) {
        if(b == e) {
            tree[node]=initiate(arr[b]);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        init(left,b,mid,arr);
        init(right,mid+1,e,arr);
        tree[node]=merge(tree[left],tree[right]);
    }
    ll query(int node,int b,int e,int i,int j) {
        if(lazy[node]!=-1) {
            tree[node]=initiate((e-b+1)*lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }lazy[node]=-1;
        }
        if(e<i || j<b) return INT_MAX;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        ll p1=query(left,b,mid,i,j);
        ll p2=query(right,mid+1,e,i,j);
        return merge(p1,p2);
    }
    void update(int node,int b,int e,int i,int j,ll x) {
        if(lazy[node]!=-1) {
            tree[node]=initiate((e-b+1)*lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }lazy[node]=-1;
        }
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=initiate((e-b+1)*x);
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
        tree[node]=merge(tree[left],tree[right]);
    }
};

int main(void) {
    int n,q; cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1; i<=n; ++i) cin>>v[i];
    SegmentTree seg(n);
    seg.init(1,1,n,v);
    while (q--) {
        int op; cin >> op;
        if(op == 1) {
            int k; ll u; cin >> k >> u;
            v[k] = u;
            seg.update(1,1,n,k,k,u);
        } else {
            int a, b; cin >> a >> b;
            cout << seg.query(1,1,n,a,b) << "\n";
        }
    }
    
}
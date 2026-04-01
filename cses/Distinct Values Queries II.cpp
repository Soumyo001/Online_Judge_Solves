#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(int n): n(n),tree(n*4,INT_MAX) { }
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
    void update(int node,int b,int e,int i,int j,int x) {
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=x;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
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
    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    SegmentTree seg(n);
    unordered_map<int,int> last, prev;
    vector<int> next(n);
    vector<int> prev(n);
    for(int i=n-1;i>=0;--i) {
        if(last.count(v[i])) next[i]=last[v[i]];
        else next[i]=INT_MAX;
        last[v[i]]=i;
    }
    last.clear();
    for(int i=0;i<n;++i) {
        if(last.count(v[i])) prev[i]=last[v[i]];
        else prev[i]=INT_MAX;
        last[v[i]]=i;
    }
    seg.build(1,0,n-1,next);
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int k,u;cin>>k>>u;
            int old=v[k-1];
            next[prev[k-1]] = next[k-1];
            v[k-1]=u;
            seg.update(1,0,n-1,k-1,k-1,u);
        } else {
            int l,r;cin>>l>>r;
            int mn = seg.query(1,0,n-1,l-1,r-1);
            if(mn > r) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
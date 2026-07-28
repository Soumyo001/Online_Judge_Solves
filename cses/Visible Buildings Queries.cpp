#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<vector<int>> tree;
    vector<int> merge(const vector<int>& a,const vector<int>& b) {
        vector<int> res=a;
        int mx = res.empty() ? INT_MIN : res.back();
        for(const int x: b) {
            if(x > mx) {
                res.push_back(x);
                mx = x;
            }
        }
        return res;
    }
public:
    SegmentTree(int n): n(n),tree(n*4) { }
    void build(int node,int b,int e,vector<int>& arr) {
        if(b == e) {
            tree[node]={arr[b]};
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=merge(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int idx,int x) {
        if(e<idx || idx<b) return;
        if(b>=idx && e<=idx) {
            tree[node]={x};
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,idx,x);
        update(right,mid+1,e,idx,x);
        tree[node]=merge(tree[left],tree[right]);
    }
    vector<int> query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return {};
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        auto p1=query(left,b,mid,i,j);
        auto p2=query(right,mid+1,e,i,j);
        return merge(p1,p2);
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    SegmentTree seg(n);
    seg.build(1,0,n-1,v);
    while(q--) {
        int a,b;cin>>a>>b;
        cout<<seg.query(1,0,n-1,a-1,b-1).size()<<"\n";
    }
}
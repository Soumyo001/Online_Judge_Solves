#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;
public:
    SegmentTree(int n): n(n),tree(n*4, 0) {}
    void build(int node,int b,int e,string& s) {
        if(b == e) {
            tree[node] = 1 << (s[b]-'a');
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,s);
        build(right,mid+1,e,s);
        tree[node]=tree[left] | tree[right];
    }
    void update(int node,int b,int e,int i,int j,char c) {
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node] = 1 << (c-'a');
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,c);
        update(right,mid+1,e,i,j,c);
        tree[node]=tree[left] | tree[right];
    }
    int query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        int p1=query(left,b,mid,i,j);
        int p2=query(right,mid+1,e,i,j);
        return p1 | p2;
    }
};

int main(void) {
    string s;cin>>s;
    int n=s.length();
    SegmentTree seg(n);
    seg.build(1,0,n-1,s);
    int q;cin>>q;
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int idx;char c;cin>>idx>>c;
            seg.update(1,0,n-1,idx-1,idx-1,c);
        } else {
            int i,j;cin>>i>>j;
            cout<<__builtin_popcount(seg.query(1,0,n-1,i-1,j-1))<<"\n";
        }
    }
}
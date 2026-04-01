#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<int> cnt;
    Node(int k): cnt(k) { }
};

class ModKSegmentTree {
private:
    int n, k;
    vector<Node> tree;
    vector<int> lazy;
    Node merge(const Node& a,const Node& b) {
        Node res=Node(k);
        for(int i=0;i<k;++i) res.cnt[i]=a.cnt[i]+b.cnt[i];
        return res;
    }
    void rotate(Node& tree,int times) {
        times = times % k;
        while(times--) {
            int temp=tree.cnt[k-1];
            for(int i=k-1;i>0;--i) tree.cnt[i]=tree.cnt[i-1];
            tree.cnt[0]=temp;
        }
    }
    void push(int node,int b,int e) {
        if(lazy[node]!=0) {
            rotate(tree[node],lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]+=lazy[node];
                lazy[(node<<1)+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }
public:
    ModKSegmentTree(int n,int k):n(n),k(k),tree(n*4,Node(k)),lazy(n*4,0) { }
    void build(int node,int b,int e) {
        if(b == e) {
            tree[node].cnt[0]=1;
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid);
        build(right,mid+1,e);
        tree[node]=merge(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int i,int j,int val=1) {
        push(node,b,e);
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            lazy[node]+=val;
            push(node,b,e);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,val);
        update(right,mid+1,e,i,j,val);
        tree[node]=merge(tree[left],tree[right]);
    }
    int query(int node,int b,int e,int i,int j) {
        push(node,b,e);
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node].cnt[0];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        int p1=query(left,b,mid,i,j);
        int p2=query(right,mid+1,e,i,j);
        return p1+p2;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    ModKSegmentTree seg(n,3);
    seg.build(1,0,n-1);
    while(q--) {
        int op,a,b;cin>>op>>a>>b;
        if(op == 0) {
            seg.update(1,0,n-1,a,b,1);
        } else {
            cout<<seg.query(1,0,n-1,a,b)<<"\n";
        }
    }
}
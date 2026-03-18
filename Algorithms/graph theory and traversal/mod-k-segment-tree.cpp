#include <bits/stdc++.h>
using namespace std;

class ModKSegTree {
private:
    struct Node {
        vector<int> cnt;
        Node(int k=3): cnt(k) { }
    };
    int n, k;
    vector<Node> tree;
    vector<int> lazy;
    int initiate(int x) { return x; }
    Node merge(const Node& a,const Node& b) {
        Node res(k);
        for(int i=0; i<k; ++i) res.cnt[i]=a.cnt[i]+b.cnt[i];
        return res;
    }
    void rotate(Node& node, int times) {
        times%=k;
        while(times--) {
            int temp = node.cnt[k-1];
            for(int i=k-1; i>0; --i) node.cnt[i] = node.cnt[i-1];
            node.cnt[0] = temp;
        }
    }
    void push(int node,int b,int e) {
        if(lazy[node]!=0) {
            rotate(tree[node], lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]+=lazy[node];
                lazy[(node<<1)+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }
public:
    ModKSegTree(int n,int k): n(n), k(k), tree(n*4,Node(k)), lazy(n*4, 0) { }
    void build(int node,int b,int e) {
        if(b == e) {
            tree[node].cnt[0]=1; // given that all the initial values in array is 0
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
    int n, q, k=3; cin >> n >> q;
    ModKSegTree seg(n,k);
    seg.build(1,0,n-1);
    while(q--) {
        int op; cin >> op;
        if(op == 0) {
            int a, b; cin >> a >> b;
            seg.update(1,0,n-1,a,b);
        } else {
            int a, b; cin >> a >> b;
            cout << seg.query(1,0,n-1,a,b) << "\n";
        }
    }
}
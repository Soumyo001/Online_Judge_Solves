#include <bits/stdc++.h>
using namespace std;
struct Node {
    int max1,max2;
    Node(int a=0,int b=0): max1(a),max2(b) { }
};
class SegmentTree {
private:
    int n;
    vector<Node> tree;
    Node initiate(int x) { return Node(x,0); }
    Node merge(const Node& a,const Node& b){
        vector<int> v = {a.max1,a.max2,b.max1,b.max2};
        sort(v.rbegin(),v.rend());
        return Node(v[0],v[1]);
    }
public:
    SegmentTree(int n): n(n),tree(n*4) { }
    void build(int node,int b,int e,vector<int>& arr) {
        if(b == e) {
            tree[node]=initiate(arr[b]);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=merge(tree[left],tree[right]);
    }
    void update(int node,int b,int e,int i,int j,int x) {
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=initiate(x);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node]=merge(tree[left],tree[right]);
    }
    Node query(int node,int b,int e,int i,int j) {
        if(e<i || j<b) return Node(0,0);
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        Node p1=query(left,b,mid,i,j);
        Node p2=query(right,mid+1,e,i,j);
        return merge(p1,p2);
    }
};

int main(void) {
    int n;cin>>n;
    SegmentTree seg(n);
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    seg.build(1,0,n-1,v);
    int q;cin>>q;
    while(q--) {
        char c; int x,y;
        cin >> c >> x >> y;
        if(c == 'U') {
            seg.update(1,0,n-1,x-1,x-1,y);
        } else {
            Node ans=seg.query(1,0,n-1,x-1,y-1);
            cout<<ans.max1+ans.max2<<"\n";
        }
    }
}
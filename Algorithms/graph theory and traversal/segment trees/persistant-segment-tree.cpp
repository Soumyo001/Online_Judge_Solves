#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val=0;
    Node *left,*right;
    Node(): val(0),left(nullptr),right(nullptr) { }
    Node(int val): val(val),left(nullptr),right(nullptr) { }
    Node(int val,Node* left,Node* right): val(val),left(left),right(right) { }
};
class PersistantSegmentTree {
private:
    int n;
    int merge(const Node* a,const Node* b) {
        return (a?a->val:0) + (b?b->val:0);
    }
public:
    PersistantSegmentTree(int n): n(n) { }
    Node* build(int b,int e,vector<int>& arr) {
        if(b == e) return new Node(arr[b]);
        int mid=(b+e)>>1;
        Node* left=build(b,mid,arr);
        Node* right=build(mid+1,e,arr);
        return new Node(merge(left,right),left,right);
    }
    Node* update(Node* node,int b,int e,int i,int j,int x) { //creates new version
        if(e<i || j<b) return node;
        if(b>=i && e<=j) return new Node(node->val+((e-b+1)*x),node->left,node->right);
        int mid=(b+e)>>1;
        Node* newLeft=update(node->left,b,mid,i,j,x);
        Node* newRight=update(node->right,mid+1,e,i,j,x);
        return new Node(merge(newLeft,newRight),newLeft,newRight);
    }
    int query(Node* node,int b,int e,int i,int j) {
        if(!node || e<i || j<b) return 0;
        if(b>=i && e<=j) return node->val;
        int mid=(b+e)>>1;
        int p1=query(node->left,b,mid,i,j);
        int p2=query(node->right,mid+1,e,i,j);
        return p1+p2;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<Node*> versions;
    PersistantSegmentTree pst(n);
    versions.push_back(pst.build(0,n-1,v));
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int idx,x;cin>>idx>>x;
            versions.push_back(pst.update(versions.back(),0,n-1,idx-1,idx-1,x));
        } else if(op == 2) {
            int l,r;cin>>l>>r;
            cout<<pst.query(versions.back(),0,n-1,l-1,r-1)<<"\n";
        } else break;
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    ll val=0;
    Node *left, *right;
    Node(): val(0),left(nullptr),right(nullptr) { }
    Node(ll val): val(val),left(nullptr),right(nullptr) { }
    Node(ll val,Node* left,Node* right): val(val),left(left),right(right) { }
};

class PersistantSegmentTree {
private:
    int n;
    ll merge(const Node* a,const Node* b) {
        return (a?a->val:0) + (b?b->val:0);
    }
public:
    PersistantSegmentTree(int n): n(n) { }
    Node* build(int b,int e,vector<ll>& arr) {
        if(b == e) return new Node(arr[b]);
        int mid=(b+e)>>1;
        Node* left = build(b,mid,arr);
        Node* right = build(mid+1,e,arr);
        return new Node(merge(left,right),left,right);
    }
    Node* update(Node* node,int b,int e,int i,int j,ll x) { // creates versions
        if(e<i || j<b) return node;
        if(b>=i && e<=j) return new Node((e-b+1)*x,node->left,node->right);
        int mid=(b+e)>>1;
        Node* newLeft = update(node->left,b,mid,i,j,x);
        Node* newRight = update(node->right,mid+1,e,i,j,x);
        return new Node(merge(newLeft,newRight),newLeft,newRight);
    }
    ll query(Node* node,int b,int e,int i,int j) {
        if(!node || e<i || j<b) return 0;
        if(b>=i && e<=j) return node->val;
        int mid=(b+e)>>1;
        ll p1=query(node->left,b,mid,i,j);
        ll p2=query(node->right,mid+1,e,i,j);
        return (p1+p2);
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<Node*> versions;
    PersistantSegmentTree pst(n);
    versions.push_back(pst.build(0,n-1,v));
    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int k,a;ll x;cin>>k>>a>>x;
            versions[k-1]=pst.update(versions[k-1],0,n-1,a-1,a-1,x);
        } else if(op == 2) {
            int k,a,b;cin>>k>>a>>b;
            cout<<pst.query(versions[k-1],0,n-1,a-1,b-1)<<"\n";
        } else {
            int k;cin>>k;
            versions.push_back(versions[k-1]);
        }
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    ll val;
    Node *left, *right;
    Node(): val(0),left(nullptr),right(nullptr) { }
    Node(ll val=0): val(val),left(nullptr),right(nullptr) { }
    Node(ll val,Node* left,Node* right): val(val),left(left),right(right) { }
};

class PersistentSegmentTree {
private:
    int n;
    ll merge(const Node* a=nullptr,const Node* b=nullptr) {
        return (a?a->val:0)+(b?b->val:0);
    }
public:
    PersistentSegmentTree(int n): n(n) { }
    Node* build(int b,int e,vector<ll>& arr) {
        if(b == e) return new Node(arr[b]);
        int mid=(b+e)>>1;
        Node* left=build(b,mid,arr);
        Node* right=build(mid+1,e,arr);
        return new Node(merge(left,right),left,right);
    }
    Node* update(Node* node,int b,int e,int idx,ll x) { //creates new version st
        if(e<idx || idx<b) return node;
        if(b>=idx && e<=idx) return new Node(x,node->left,node->right);
        int mid=(b+e)>>1;
        Node* newLeft=update(node->left,b,mid,idx,x);
        Node* newRight=update(node->right,mid+1,e,idx,x);
        return new Node(merge(newLeft,newRight),newLeft,newRight);
    }
    ll query(Node* node,int b,int e,int i,int j) {
        if(!node || e<i || j<b) return 0;
        if(b>=i && e<=j) return node->val;
        int mid=(b+e)>>1;
        ll p1=query(node->left,b,mid,i,j);
        ll p2=query(node->right,mid+1,e,i,j);
        return p1+p2;
    }
};

int main(void) {
    int n,q;cin>>n>>q;vector<ll> v(n+1);for(int i=1;i<=n;++i) cin>>v[i];
    PersistentSegmentTree pst(n);
    vector<Node*> versions;
    versions.push_back(pst.build(1,n,v));
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int k,a; ll x; cin>>k>>a>>x;
            versions[k-1]=pst.update(versions[k-1],1,n,a,x);
        }
        else if(op == 2) {
            int k,i,j;cin>>k>>i>>j;
            cout<<pst.query(versions[k-1],1,n,i,j)<<"\n";
        }
        else if(op == 3){
            int k;cin>>k;
            if(k-1>=0 && k-1<versions.size())
                versions.push_back(versions[k-1]);
        }
    }
}
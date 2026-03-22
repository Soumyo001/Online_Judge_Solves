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
    ll merge(const Node* a=nullptr,const Node* b=nullptr,const ll val=0) { 
        ll res = 0;
        if(a) res+=a->val;
        if(b) res+=b->val;
        res+=val;
        return res;
    }
public:
    PersistentSegmentTree(int n): n(n) { }
    Node* build(int b,int e,vector<ll>& arr) {
        if(b == e) return new Node(arr[b]);
        int mid = (b+e)>>1;
        Node* newLeft = build(b,mid,arr);
        Node* newRight = build(mid+1,e,arr);
        return new Node(merge(newLeft,newRight),newLeft,newRight);
    }
    Node* update(Node* node,int b,int e,int i,int j,int x) {
        if(e<i || j<b) return node;
        if(b>=i && e<=j) 
            return new Node(merge(node,nullptr,(e-b+1)*x*1LL),node->left,node->right);
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
        return p1+p2;
    }
};

int main(void) {
    int n; cin >> n;
    PersistentSegmentTree pst(n);
    vector<ll> v(n);
    vector<Node*> versions;
    for(int i=0;i<n;++i) cin>>v[i];
    Node* root0=pst.build(0,n-1,v);
    versions.push_back(root0);
    while(true) {
        int op;cin >> op;
        if(op == 1) {
            int idx, x; cin >> idx >> x;
            Node* newVersion = pst.update(versions.back(),0,n-1,idx-1,idx-1,x);
            versions.push_back(newVersion);
        } else if(op == 2) {
            int a, b; cin >> a >> b;
            cout<<pst.query(versions.back(),0,n-1,a-1,b-1)<<"\n";
        } else break;
    }
}
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i]==curr) return i;
    }
    return -1;
}

Node* buildTree(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    Node* p=new Node(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=buildTree(pre_order,in_order,start,pos-1);
    p->right=buildTree(pre_order,in_order,pos+1,end);
    return p;
}

Node* connect(Node* root) {
    if(!root) return NULL;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* n = q.front();q.pop();
        if(n!=NULL){
            n->next = q.front();
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    return root;
}

void preorder(Node* root, unordered_map<int,bool>& vis){
    if(!root) return;
    if(!vis[root->val]){
        Node* temp = root;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            vis[temp->val] = true;
            temp = temp->next;
        }
        cout<<"\n";
    }
    preorder(root->left, vis);
    preorder(root->right, vis);
}

int main(void){
    int n;cin>>n;
    int pre_order[n], in_order[n];
    for(int i=0;i<n;++i) cin>>pre_order[i];
    for(int i=0;i<n;++i) cin>>in_order[i];
    Node* root = buildTree(pre_order,in_order,0,n-1);
    root = connect(root);
    unordered_map<int,bool> vis;
    preorder(root,vis);
}
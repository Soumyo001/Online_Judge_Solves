#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i]==curr) return i;
    }
    return -1;
}

TreeNode* buildTree(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    TreeNode* p=new TreeNode(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=buildTree(pre_order,in_order,start,pos-1);
    p->right=buildTree(pre_order,in_order,pos+1,end);
    return p;
}

void pre(TreeNode* root, vector<int>& res){
    if(root==NULL) return;
    res.push_back(root->val);
    pre(root->left,res);
    pre(root->right,res);
}

void flatten(TreeNode* root) {
    if(!root) return;
    vector<int> n;
    pre(root, n);
    TreeNode* curr = root;
    curr->val = n[0];
    curr->left = nullptr;
    for(int i=1;i<n.size();++i){
        curr->right = new TreeNode(n[i]);
        curr = curr->right;
    }
}

int main(void){
    int n;cin>>n;
    int pre_order[n], in_order[n];
    for(int i=0;i<n;++i) cin>>pre_order[i];
    for(int i=0;i<n;++i) cin>>in_order[i];
    TreeNode* root = buildTree(pre_order,in_order,0,n-1);
    flatten(root);
    TreeNode* temp = root;
    while(temp!=NULL) cout<<temp->val<<" ",temp=temp->right;
}
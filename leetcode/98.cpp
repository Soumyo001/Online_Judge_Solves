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

TreeNode* build(vector<int>& pre_order,vector<int>& in_order,unordered_map<int,int>& pos,int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    TreeNode* p=new TreeNode(curr);
    if(start==end) return p;
    p->left=build(pre_order,in_order,pos,start,pos[curr]-1);
    p->right=build(pre_order,in_order,pos,pos[curr]+1,end);
    return p;
}

void inorder(TreeNode* root, vector<int>& n){
    if(root == NULL) return;
    inorder(root->left, n);
    n.push_back(root->val);
    inorder(root->right, n);
}

bool isValidBST(TreeNode* root) {
    vector<int> n;
    inorder(root, n);
    for(int i=0;i<n.size()-1;++i) if(n[i] >= n[i+1]) return false;
    return true;
}

int main(void){
    int n;cin>>n;
    vector<int> pre(n,0);
    vector<int> in(n, 0);
    unordered_map<int,int> pos;
    for(int i=0;i<n;++i) cin>>in[i], pos[in[i]] = i;
    for(int i=0;i<n;++i) cin>>pre[i];
    TreeNode* root = build(pre,in,pos,0,pre.size()-1);
    cout<<isValidBST(root);
}
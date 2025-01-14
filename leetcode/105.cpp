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

TreeNode* build(queue<int>& q, unordered_map<int,int>& m, int start, int end){
    if(start > end) return NULL;
    int curr = q.front();q.pop();
    auto n = new TreeNode(curr);
    if(start == end) return n;
    n->left = build(q,m,start,m[curr]-1);
    n->right = build(q,m,m[curr]+1,end);
    return n;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> m;
    queue<int> q;
    for(int i=0;i<inorder.size();++i) m[inorder[i]] = i;
    for(int i=0;i<preorder.size();++i) q.push(preorder[i]);
    return build(q, m, 0, preorder.size()-1);
}

void inorder_trav(TreeNode* root){
    if(root==NULL) return;
    inorder_trav(root->left);
    cout<<root->val<<" ";
    inorder_trav(root->right);
}

int main(void){
    vector<int> in = {9,3,15,20,7};
    vector<int> pre = {3,9,20,15,7};
    inorder_trav(buildTree(pre,in));
}
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

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return root;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        auto n = q.front();q.pop();
        if(n!=NULL){
            if(n->left!=NULL && n->right!=NULL){
                swap(n->left,n->right);
                q.push(n->left);
                q.push(n->right);
            }else if(n->left!=NULL){
                n->right=n->left;
                n->left=NULL;
                q.push(n->right);
            }else if(n->right!=NULL){
                n->left=n->right;
                n->right=NULL;
                q.push(n->left);
            }
        }else if(!q.empty()) q.push(NULL);
    }
    return root;
}

  int main(void){
    TreeNode* root = new TreeNode(4);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(5);
    TreeNode* n5 = new TreeNode(6);
    TreeNode* n6 = new TreeNode(7);
    TreeNode* n7 = new TreeNode(9);
    root->left = n1;
    root->right = n6;
    n1->left = n3;
    n1->right = n2;
    n6->left = n5;
    n6->right = n7;
}
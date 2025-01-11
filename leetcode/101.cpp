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


bool c(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    return c(left->left, right->right) && c(left->right, right->left) 
    && left->val == right->val;
}

bool isSymmetric(TreeNode* root) {
    return c(root->left, root->right);
}

int main(void){
    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n5;
    n2->left = n6;
    n2->right = n4;

    cout<<isSymmetric(root);
}
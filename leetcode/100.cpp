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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && p->val==q->val;
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
    n2->left = n4;
    n2->right = n6;

    cout<<isSameTree(root->left, root->right);
}
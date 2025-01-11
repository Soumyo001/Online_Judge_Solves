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

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int l =1;
    while(!q.empty()){
        auto n = q.front();q.pop();
        if(n!=NULL){
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }else if(!q.empty()){
            ++l;
            q.push(NULL);
        }
    }
    return l;
}

 int main(void){
   TreeNode* root = new TreeNode(1);
   TreeNode* n1 = new TreeNode(2);
   TreeNode* n2 = new TreeNode(3);
   TreeNode* n3 = new TreeNode(4);
   TreeNode* n4 = new TreeNode(5);
   root->left = n1;
   root->right = n2;
   n2->right = n4;
   n2->right = n3;
    cout<<maxDepth(root);
}
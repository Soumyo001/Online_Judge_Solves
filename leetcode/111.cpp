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

int minDepth(TreeNode* root) {
    if(root==NULL) return 0;
    int ln = 0;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* n = q.front();q.pop();
        bool l = false, r = false;
        if(n!=NULL){
            if(n->left!=NULL) q.push(n->left);
            else l = true;
            if(n->right!=NULL) q.push(n->right);
            else r = true;
            if(l && r) break;
        }else if(!q.empty()){
            q.push(NULL);++ln;
        }
    }
    return ln+1;
}

int main(void){
    int i = 2;
    TreeNode* root = new TreeNode(i);++i;
    TreeNode* temp = root;
    while(i<=6){
        root->right = new TreeNode(i);
        root = root->right;
        ++i;
    }
    root = temp;
    cout<<minDepth(root);
}
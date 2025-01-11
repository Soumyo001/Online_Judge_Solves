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

vector<int> rightSideView(TreeNode* root){
    if(root == NULL) return {};
    queue<TreeNode*> q;
    vector<int> ans;
    q.push(root);
    int n = q.size();
    q.push(NULL);
    int i = 0;
    while (!q.empty())
    {
        TreeNode* t = q.front();q.pop();
        if(t!=NULL){
            if(i == n - 1) ans.push_back(t->val);
            if(t->left!=NULL) q.push(t->left);
            if(t->right!=NULL) q.push(t->right);
            ++i;
        }else if(!q.empty()){
            i = 0;
            n = q.size();
            q.push(NULL);
        }
    }
    return ans;
}

 int main(void){
    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* n4 = new TreeNode(5);

    root->left = n1;
    root->right = n2;
    n1->right = n4;
    n2->right = n3;
    
    for(const auto i : rightSideView(root)) cout<<i<<" ";
 }
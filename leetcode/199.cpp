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

vector<int> rightSideView(TreeNode* root) {
    if(root == NULL) return {};
    queue<TreeNode*> q;
    q.push(root);
    int sz = q.size();
    q.push(NULL);
    vector<int> v;
    int c = 0;
    while(!q.empty()){
        const TreeNode* n = q.front();q.pop();
        if(n != NULL){
            if(n->left != NULL) q.push(n->left);
            if(n->right != NULL) q.push(n->right);
            ++c;
            if(c == sz) v.push_back(n->val);
        }else if(!q.empty()){
            sz = q.size();
            c = 0;
            q.push(NULL);
        }
    }
    return v;
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
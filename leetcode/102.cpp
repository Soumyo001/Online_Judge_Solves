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

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
        int n = q.size();
        vector<int> v;
        for(int i=1;i<=n;++i){
            auto n = q.front();q.pop();
            v.push_back(n->val);
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
        ans.push_back(v);
    }
    return ans;
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
    for(auto& i:levelOrder(root)){
        for(auto& j:i) cout<<j<<" ";
        cout<<"\n";
    }
}
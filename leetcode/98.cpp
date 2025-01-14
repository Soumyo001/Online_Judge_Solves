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

TreeNode* build(queue<int>& q, unordered_map<int,int>& pos, int start, int end){
    if(start>end) return NULL;
    int curr = q.front();q.pop();
    auto n = new TreeNode(curr);
    if(start == end) return n;
    n->left = build(q, pos, start, pos[curr] - 1);
    n->right = build(q,pos, pos[curr] + 1, end);
    return n;
}

void inorder_trav(TreeNode* root, vector<int>& res){
    if(root == NULL) return;
    inorder_trav(root->left, res);
    res.push_back(root->val);
    inorder_trav(root->right, res);
}

bool isValidBST(TreeNode* root){
    vector<int> res;
    inorder_trav(root, res);
    if(res.size() == 1) return true;
    if(res.size() == 2) if(res[0]<res[1]) return true; else return false;
    bool is = true;
    for(int i = 1;i<res.size()-1;++i) is &= (res[i-1]<res[i] && res[i]<=res[i+1]);
    return is;
}

int main(void){
    int n;cin>>n;
    vector<int> pre(n,0);
    vector<int> in(n, 0);
    queue<int> q;
    unordered_map<int,int> pos;
    for(int i=0;i<n;++i) cin>>in[i], pos[in[i]] = i;
    for(int i=0;i<n;++i) cin>>pre[i], q.push(pre[i]);
    TreeNode* root = build(q,pos,0,pre.size()-1);

    cout<<isValidBST(root);
}
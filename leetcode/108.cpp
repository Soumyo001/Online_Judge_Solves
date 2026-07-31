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


TreeNode* buildBST(vector<int>& v, int start, int end) {
    if(start == end) return NULL;
    int mid = (start + end) >> 1;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = buildBST(v, start, mid);
    root->right = buildBST(v, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums, 0, nums.size());
}

int main(void) {
    int n;cin>>n;vector<int> v(n, 0);for(int i=0;i<n;++i) cin>>v[i];
    TreeNode* root = sortedArrayToBST(v);
}
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

int search(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i]==curr) return i;
    }
    return -1;
}

TreeNode* buildTree(int pre_order[],int in_order[],int start,int end){
    static int idx=0;
    if(start>end) return NULL;
    int curr=pre_order[idx];
    idx++;
    TreeNode* p=new TreeNode(curr);
    if(start==end) return p;
    int pos=search(in_order,start,end,curr);
    p->left=buildTree(pre_order,in_order,start,pos-1);
    p->right=buildTree(pre_order,in_order,pos+1,end);
    return p;
}


bool ans = false;
void dfs(TreeNode* root, int sum, int target){
    if(root->left != NULL) dfs(root->left, sum, target + root->val);
    if(root->right != NULL) dfs(root->right, sum, target + root->val);
    if(!ans && root->left==NULL && root->right==NULL) ans = ((target+root->val) == sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    dfs(root, targetSum, 0);
    return ans;
}

int main(void){
    int n,t;cin>>n>>t;
    int pre_order[n], in_order[n];
    for(int i=0;i<n;++i) cin>>pre_order[i];
    for(int i=0;i<n;++i) cin>>in_order[i];
    TreeNode* root = buildTree(pre_order,in_order,0,n-1);
    cout<<hasPathSum(root,t);
}
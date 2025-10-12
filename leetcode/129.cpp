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

void dfs(TreeNode* root, vector<int>& numbers, int& sum){
    if(root == NULL){
        sum /= 10;
        return;
    }
    //cout<<sum<<" ";
    sum+= root->val;
    //cout<<"+ "<<root->val<<" = "<<sum<<"\n";
    if(root->left == NULL && root->right == NULL) {
        numbers.push_back(sum);
    }else{
        sum*= 10;
        dfs(root->left, numbers, sum);
        sum*= 10;
        dfs(root->right, numbers, sum);
    }
    sum /= 10;
    //cout<<sum<<"\n";
}

int sumNumbers(TreeNode* root) {
    vector<int> numbers;
    int sum = 0;
    dfs(root, numbers, sum);
    int ans = 0;
    for(const auto& i:numbers) ans+=i;
    return ans;
}


int main(void){
    int n;cin>>n;
    int pre_order[n], in_order[n];
    for(int i=0;i<n;++i) cin>>pre_order[i];
    for(int i=0;i<n;++i) cin>>in_order[i];
    TreeNode* root = buildTree(pre_order, in_order, 0, n-1);
    cout<<sumNumbers(root);
}
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

void dfs(TreeNode* curr, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent, vector<TreeNode*>& leaf){
    parent[curr] = par;
    if(curr->left == NULL && curr->right == NULL) leaf.push_back(curr);
    else{
        if(curr->left != NULL) dfs(curr->left, curr, parent, leaf);
        if(curr->right != NULL) dfs(curr->right, curr, parent, leaf);
    }
}
vector<int> get_path(TreeNode* root, const unordered_map<TreeNode*, TreeNode*>& parent){
    vector<int> v;
    TreeNode* n = root;
    while(n != NULL){
        v.push_back(n->val);
        n = parent.at(n);
    } 
    reverse(v.begin(), v.end());
    return v;
}
vector<string> binaryTreePaths(TreeNode* root) {
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<TreeNode*> leaf;
    dfs(root, NULL, parent, leaf);
    vector<vector<int>> paths;
    for(const auto& i:leaf) paths.push_back(get_path(i, parent));
    vector<string> ans;
    for(const vector<int>& i: paths){
        string s = "";
        for(int j=0; j<(int)i.size(); ++j){
            s += to_string(i[j]);
            s += (j == (int)i.size()-1 ? "":"->");
        }
        ans.push_back(s);
    }
    return ans;
}

int main(void){
    int n;cin>>n;
    int pre_order[n], in_order[n];
    for(int i=0;i<n;++i) cin>>pre_order[i];
    for(int i=0;i<n;++i) cin>>in_order[i];
    TreeNode* root = buildTree(pre_order, in_order, 0, n-1);
    const vector<string> paths = binaryTreePaths(root);
    for(const string s : paths) cout<<s<<"\n";
}
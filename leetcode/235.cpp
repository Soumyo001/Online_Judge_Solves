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

TreeNode *f, *s;

TreeNode* build(queue<int> q, const unordered_map<int,int> pos, int start, int end, int p, int qq){
    if(start>end) return NULL;
    int curr = q.front();q.pop();
    auto n = new TreeNode(curr);
    if(curr == p) f = n;
    else if(curr == qq) s = n;
    if(start == end) return n;
    n->left = build(q,pos,start,pos.at(curr)-1,p,qq);
    n->right = build(q,pos,pos.at(curr)+1,end,p,qq);
    return n;
}

void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent, TreeNode* par){
    if(root == NULL) return;
    parent[root] = par;
    if(root->left!=NULL) dfs(root->left, parent, root);
    if(root->right!=NULL) dfs(root->right, parent, root);
}
vector<TreeNode*> lcs(TreeNode* root, const unordered_map<TreeNode*,TreeNode*> parent){
    vector<TreeNode*> v;
    TreeNode* node = root;
    while(node!=NULL){
        v.push_back(node);
        node = parent.at(node);
    }
    reverse(v.begin(),v.end());
    return v;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*,TreeNode*> parent;
    dfs(root, parent, NULL);
    vector<TreeNode*> vp = lcs(p, parent);
    vector<TreeNode*> vq = lcs(q, parent);
    TreeNode* ansc = NULL;
    for(int i=0;i<min(vp.size(),vq.size());++i){
        if(vp[i] == vq[i]) ansc = vp[i];
        else break;
    }
    return ansc;
}

int main(void){
    int n;cin>>n;
    vector<int> pre(n,0);
    vector<int> in(n, 0);
    queue<int> q;
    unordered_map<int,int> pos;
    for(int i=0;i<n;++i) cin>>in[i], pos[in[i]] = i;
    for(int i=0;i<n;++i) cin>>pre[i], q.push(pre[i]);
    int p, qq;cin>>p>>qq;
    TreeNode* root = build(q,pos,0,pre.size()-1,p,qq);
    cout<<lowestCommonAncestor(root, f, s)->val;
}
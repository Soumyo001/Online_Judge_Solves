#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
        Node *p = NULL, *q = NULL;
        void dfs(Node* root, unordered_map<Node*,Node*>& parent, Node* par,int n1,int n2){
            if(root == NULL) return;
            if(root->data == n1) p = root;
            else if(root->data == n2) q = root;
            parent[root] = par;
            if(root->left!=NULL) dfs(root->left,parent,root,n1,n2);
            if(root->right!=NULL) dfs(root->right,parent,root,n1,n2);
        }
        vector<Node*> lcs(Node* root, const unordered_map<Node*,Node*>& parent){
            vector<Node*> v;
            Node* node = root;
            while(node!=NULL){
                v.push_back(node);
                node = parent.at(node);
            }
            reverse(v.begin(),v.end());
            return v;
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            unordered_map<Node*,Node*> parent;
            dfs(root, parent, NULL, n1, n2);
            vector<Node*> vp = lcs(p, parent);
            vector<Node*> vq = lcs(q, parent);
            Node* ansc = NULL;
            for(int i=0;i<min(vp.size(),vq.size());++i){
                if(vp[i]==vq[i]) ansc = vp[i];
                else break;
            }
            return ansc;
        }

};

Node* buildTree(string str)
{   

    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if(currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
        if(currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t = 1;
	// scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
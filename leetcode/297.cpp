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

TreeNode* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    // Create the root of the tree
    TreeNode *root = new TreeNode(stoi(ip[0]));
    // Push the root to the queue
    queue<TreeNode *> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        TreeNode *currNode = queue.front();
        queue.pop();
        // Get the current Node's value from the string
        string currVal = ip[i];
        // If the left child is not null
        if (currVal != "null") {
            // Create the left child for the current Node
            currNode->left = new TreeNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        // If the right child is not null
        if (currVal != "null") {
            // Create the right child for the current Node
            currNode->right = new TreeNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder_trav(TreeNode* root, vector<int>& nodes){
    if(root == NULL) {
        nodes.push_back(INT_MIN);
        return;
    };
    nodes.push_back(root->val);
    inorder_trav(root->left, nodes);
    inorder_trav(root->right, nodes);
}

string serialize(TreeNode* root) {
    vector<int> nodes;
    inorder_trav(root, nodes);
    string s = "";
    for(auto i : nodes){
        if(i == INT_MIN) s+="N,";
        else s+=to_string(i)+",";
    }
    if(!nodes.empty()) s.pop_back();
    // cout<<s<<"\n";
    return s;
}

TreeNode* deserRec(queue<int>& q){
    int n = q.front();q.pop();
    if(n == INT_MIN) return nullptr;
    TreeNode* t = new TreeNode(n);
    t->left = deserRec(q);
    t->right = deserRec(q);
    return t;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    string val;
    queue<int> q;
    while(getline(ss, val, ',')){
        int n = val == "N"? INT_MIN:stoi(val);
        // cout<<n<<" ";
        q.push(n);
    }
    return deserRec(q);
}

void inorder(TreeNode* root){
    if(root == NULL){
        cout<<" null ";
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main() {
    int tc = 1;
    // scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        TreeNode *root = buildTree(treeString);

        TreeNode* getRoot = deserialize(serialize(root));
        inorder(getRoot);

    }

    return 0;
}

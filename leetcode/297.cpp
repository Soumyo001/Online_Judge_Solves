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

string serialize(TreeNode* root) {
    if(root == NULL) return "null,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}

TreeNode* deserialize_helper(queue<string>& q){
    string s = q.front(); q.pop();
    if(s == "null") return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    root->left = deserialize_helper(q);
    root->right = deserialize_helper(q);
    return root;
}

TreeNode* deserialize(string data) {
    queue<string> q;
    string s = "";
    for(int i=0; i<data.size(); ++i){
        if(data[i] == ','){
            q.push(s);
            s = "";
        }else s += data[i];
    }
    // if(s.size()!=0) q.push(s); // no need if guranteed last index has an ','
    return deserialize_helper(q);
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

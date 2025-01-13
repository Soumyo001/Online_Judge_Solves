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

Node *buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
  public:
    void preorder_trav(Node* root, vector<int>& v){
        if(root == NULL){
            v.push_back(INT_MIN);
            return;
        }
        v.push_back(root->data);
        preorder_trav(root->left, v);
        preorder_trav(root->right, v);
    }
    vector<int> serialize(Node *root) {
        vector<int> v;
        preorder_trav(root, v);
        return v;
    }
    
    Node* deserRec(queue<int>& q){
        int n = q.front();q.pop();
        if(n == INT_MIN) return NULL;
        Node* t = new Node(n);
        t->left = deserRec(q);
        t->right = deserRec(q);
        return t;
    }

    Node *deSerialize(vector<int> &arr) {
        queue<int> q;
        for(const auto i : arr) q.push(i);
        return deserRec(q);
    }
};

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;
    _deleteTree(node->left);
    _deleteTree(node->right);
    delete node;
}

void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
};

Node* newNode(int val) {
    return new Node(val);
}

class Solution {
  public:

    vector<vector<int>> levelOrder(Node *root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> v;
        while(!q.empty()){
            auto n = q.front();q.pop();
            if(n!=NULL){
                v.push_back(n->data);
                if(n->left!=NULL) q.push(n->left);
                if(n->right!=NULL) q.push(n->right);
            }else if(!q.empty()){
                ans.push_back(v);
                v.clear();
                q.push(NULL);
            }
        }
        ans.push_back(v);
        return ans;
    }
};

void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t = 1;
    // scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<vector<int>> res = ob.levelOrder(root);
        for (auto level : res) {
            for (int ele : level)
                cout << ele << " ";
            cout<<"\n";
        }
    }
    return 0;
}
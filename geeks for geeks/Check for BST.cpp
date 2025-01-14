#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  
    void inorder_trav(Node* root, vector<int>& res){
    if(root == NULL) return;
    inorder_trav(root->left, res);
    res.push_back(root->data);
    inorder_trav(root->right, res);
    }

    bool isBST(Node* root) {
            vector<int> res;
    inorder_trav(root, res);
    if(res.size() == 1) return true;
    if(res.size() == 2) if(res[0]<res[1]) return true; else return false;
    bool is = true;
    for(int i = 1;i<res.size()-1;++i) is &= (res[i-1]<res[i] && res[i]<=res[i+1]);
    return is;
    }
};

Node* buildTree(string str) {

    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
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

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t = 1;
    // string tc;
    // getline(cin, tc);
    // t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
    }
    return 0;
}
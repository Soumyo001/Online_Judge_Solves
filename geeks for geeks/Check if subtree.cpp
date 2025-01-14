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

class Solution
{
  public:
    bool isSame(Node* t, Node* s){
        if(t == NULL && s == NULL) return true;
        if(t == NULL || s == NULL) return false;
        return isSame(t->left, s->left) && isSame(t->right, s->right) && t->data == s->data;
    }
    bool is = false;
    bool inorder_trav(Node* t, int val, Node* s){
        if(t == NULL) return is;
        if(t->data == val) is |= isSame(t, s);
        is |= inorder_trav(t->left, val, s);
        is |= inorder_trav(t->right, val, s);
        return is;
    }
    bool isSubTree(Node* T, Node* S) 
    {
        return inorder_trav(T, S->data, S);
        
    }
};

int main() {
    int tc = 1;
    // scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";
    }
    return 0;
}
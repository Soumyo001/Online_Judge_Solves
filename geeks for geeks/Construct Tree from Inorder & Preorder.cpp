#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution {
  public:
    Node* build(queue<int>& q, unordered_map<int,int>& m, int start, int end){
        if(start>end) return NULL;
        int curr = q.front();q.pop();
        auto n = new Node(curr);
        if(start==end) return n;
        n->left = build(q,m,start,m[curr]-1);
        n->right = build(q,m,m[curr]+1,end);
        return n;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        queue<int> q;
        unordered_map<int,int> m;
        for(int i=0;i<preorder.size();++i) q.push(preorder[i]);
        for(int i=0;i<inorder.size();++i) m[inorder[i]] = i;
        return build(q,m,0,preorder.size()-1);
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        printPostOrder(root);
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertBST(Node* root, int key) {
    if(root == NULL) return new Node(key);
    if(root->val > key) root->left = insertBST(root->left, key);
    else if(root->val < key) root->right = insertBST(root->right, key);
    return root;
}

bool searchBST(Node* root, int key) {
    if(root == NULL) return false;
    if(root->val == key) return true;
    else if(key < root->val) return searchBST(root->left, key);
    else return searchBST(root->right, key);
}

Node* inorder_succ(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key) {
    if(root == NULL) return root;
    if(key < root->val) root->left = deleteBST(root->left, key);
    else if(root->val < key) root->right = deleteBST(root->right, key);
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* is = inorder_succ(root->right); // left-most node of right subtree which can have at most 1 child on the right
        root->val = is->val;
        root->right = deleteBST(root->right, is->val);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(void) {
    int n; cin >> n;
    Node* root = NULL;
    for(int i=0; i<n; ++i) {
        int x; cin >> x; 
        root = insertBST(root, x);
    }
    int op; cin>>op;
    while(op--) {
        int x; cin>>x;
        if(x == 1) {
            int key;cin>>key;
            cout<<searchBST(root, key)<<"\n";
        } else if(x == 2) {
            int key; cin>>key;
            root = deleteBST(root, key);
            inorder(root);
            cout<<"\n";
        } else inorder(root), cout<<"\n";
    }
}
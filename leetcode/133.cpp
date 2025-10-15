#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node* node, Node*& root, unordered_map<Node*, Node*>& vis){
    if(vis.count(node)){
        root = vis[node];
        return;
    }
    root = new Node(node->val);
    vis[node] = root;
    for(int i=0; i<node->neighbors.size(); ++i){
        if(node->neighbors[i] != NULL){
            root->neighbors.push_back(NULL);
            dfs(node->neighbors[i], root->neighbors[root->neighbors.size() - 1], vis);
        }
    }
}

Node* cloneGraph(Node* node) {
    if(node == NULL) return node;
    Node* root = NULL;
    unordered_map<Node*, Node*> vis;
    dfs(node, root, vis);
    return root;
}

int main(void){
    // too lazy to make inputs for it :)
}
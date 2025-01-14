#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));
    if (pNode) {
        int i;
        pNode->isLeaf = false;
        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }
    return pNode;
}

class Solution
{
    public:
        void insert(struct TrieNode *root, string key)
        {
            for(int i=0;i<key.length();++i){
                int id = key[i] - 'a';
                if(root->children[id] == NULL)
                    root->children[id] = new TrieNode();
                root = root->children[id];
            }
            root->isLeaf = true;
        } 
        bool search(struct TrieNode *root, string key) 
        {
            for(int i=0;i<key.length();++i){
                int id = key[i] - 'a';
                if(root->children[id] == NULL) return false;
                root = root->children[id];
            }
            return root->isLeaf;
        }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        
        Solution obj;
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++) obj.insert(root, keys[i]);
        string abc;
        cin >> abc;

        if (obj.search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
    
    }
    return 0;
}
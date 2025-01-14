#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool endMark;
    unordered_map<int, Node*> next;
    Node() {
        endMark = false;
        for(int i=0;i<26;++i) next[i] = NULL;
    }
};

void insert_rec(string s, Node* root, int idx, int len){
    if(idx == len){
        root->endMark = true;
        return;
    }
    // cout<<s[idx]<<" ";
    int id = s[idx] - 'a';
    if(root->next[id] == NULL)
        root->next[id] = new Node();
    insert_rec(s, root->next[id], ++idx, len);
}

bool search_rec(string s, Node* root, int idx, int len){
    if(idx == len) return root->endMark;
    int id = s[idx] - 'a';
    if(root->next[id] == NULL) return false;
    return search_rec(s, root->next[id], ++idx, len);
}

void insert(string s, Node* root){
    int len = s.length();
    for(int i=0;i<len;++i){
        int id = s[i] - 'a';
        if(root->next[id] == NULL) root->next[id] = new Node();
        root = root->next[id];
    }
    root->endMark = true;
}

bool search(string s, Node* root){
    int len = s.length();
    for(int i=0;i<len;++i){
        int id = s[i] - 'a';
        if(root->next[id] == NULL) return false;
        root = root->next[id]; 
    }
    return root->endMark;
}

int main(void){
    Node* root = new Node();
    vector<string> v;
    string s;
    cout<<"Number of Words : ";
    int num_word;cin>>num_word;
    for(int i=0;i<num_word;++i){
         cin>>s;
         insert(s,root);
    }
    cout<<"Query : ";
    int query; cin>>query;
    while(query--){
        cin>>s;
        cout<<"For word : "<<s<<" -> "<<search(s,root)<<"\n";
    }
}
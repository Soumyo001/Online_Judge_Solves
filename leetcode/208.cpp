#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct Node{
        bool endMark;
        unordered_map<int, Node*> next;
        Node(){
            endMark = false;
            for(int i=0;i<26;++i) next[i] = NULL;
        }
    };
    Node* root;
    Trie() : root(new Node()){}

    void insert(string s) {
        Node* curr = root;
        int len = s.length();
        for(int i=0;i<len;++i){
            int id = s[i] - 'a';
            if(curr->next[id] == NULL) curr->next[id] = new Node();
            curr = curr->next[id];
        }
        curr->endMark = true;
    }
    
    bool search(string word) {
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;++i){
            int id = word[i] - 'a';
            if(curr->next[id] == NULL) return false;
            curr = curr->next[id];
        }
        return curr->endMark;
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        int len = prefix.length();
        for(int i=0;i<len;++i){
            int id = prefix[i] - 'a';
            if(curr->next[id]==NULL) return false;
            curr = curr->next[id];
        }
        return true;
    }
};

int main(void){
    cout<<"NUMBER OF WORDS : ";
    int n;cin>>n;
    Trie* trie = new Trie();
    for(int i=0;i<n;++i){
        string s;cin>>s;
        trie->insert(s);
    }
    cout<<"QUERY : ";
    int q;cin>>q;
    while(q--){
        string s,pre;cin>>s>>pre;
        cout<<"FOR WORD : "<<s<<" -> "<<trie->search(s)<<" and prefix : "<<pre<<" -> "<<trie->startsWith(pre)<<"\n";
    }
}
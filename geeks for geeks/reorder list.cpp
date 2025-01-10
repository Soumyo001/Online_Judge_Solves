#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

class Solution {
  public:
    void reorderList(Node* head) {
        vector<int> v;
        Node* temp = head;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        vector<int> a;
        for(int i=0,j=v.size()-1;i<=v.size()/2 && j>=v.size()/2;++i,--j){
            if(i!=j){
                a.push_back(v[i]);
                a.push_back(v[j]);
            }else a.push_back(v[j]);
        }
        temp = head;
        for(int i=0;i<a.size();++i){
            temp->data = a[i];
            temp=temp->next;
        }
    }
};

int main() {
    int t=1, k;
    // cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10<<" ";
        node = node->next;
    }
    cout << "\n";
}

class Solution {
  public:
    int add(Node* head){
        if(head->next == NULL){
            int res = head->data+1;
            head->data = res % 10;
            return res / 10;
        }
        
        int carry = add(head->next);
        if(carry!=0) {
            carry += head->data;
            head->data = carry % 10;
        }
        return carry / 10;
    }
    
    Node* addOne(Node* head) {
        int carry = add(head);
        Node* temp = head;
        if(carry != 0){
            temp = new Node(carry);
            temp->next = head; 
        }
        return temp;    
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}
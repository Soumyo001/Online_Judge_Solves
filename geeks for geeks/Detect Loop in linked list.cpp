#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
  public:

    bool detectLoop(Node* head) {
        if(head==NULL || head->next==NULL) return false;
        Node* tor = head;
        Node* hair = head->next;
        while(tor!=hair){
            if(hair->next==NULL || hair->next->next==NULL) return false;
            hair=hair->next->next;
            tor=tor->next;
        }
        return true;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head))
            cout << "true\n";
        else
            cout << "false\n";

        unordered_set<Node*> visited;
        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
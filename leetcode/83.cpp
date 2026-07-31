#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        if(temp->next != NULL && temp->val == temp->next->val) {
            if(temp->next->next != NULL) temp->next = temp->next->next;
            else temp->next = NULL;
        }
        else temp = temp->next;
    }
    return head;
}

int main(void) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head = deleteDuplicates(head);
    ListNode* temp = head;
    while(temp != NULL) cout<<temp->val<<" ", temp = temp->next;
}
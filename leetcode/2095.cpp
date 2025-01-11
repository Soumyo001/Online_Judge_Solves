#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next = NULL;
    ListNode(){}
    ListNode(int val):val(val),next(NULL){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};

ListNode* head;

ListNode* deleteMiddle(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode *slow=head, *fast=head, *tail=NULL;
    while(fast && fast->next){
        tail = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(tail!=NULL){
        tail->next = slow->next;
        slow->next = NULL;
    }else{
        tail = head = NULL;
    }
    return head;
}

int main(void){
    string s;
    getline(cin, s);
    // int n; cin>>n;
    // cin.ignore();
    istringstream ss(s);
    int val;
    ListNode* temp = head = new ListNode(-1);
    while(ss>>val){
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    ListNode* ans = deleteMiddle(head->next);
    while (ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    
}
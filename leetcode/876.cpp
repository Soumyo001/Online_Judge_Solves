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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    ListNode* ans = middleNode(head->next);
    while (ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    
}
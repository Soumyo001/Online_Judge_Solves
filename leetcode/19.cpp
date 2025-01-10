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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL) return head;
    ListNode* temp = head;
    ListNode* tail = NULL;
    int c = 0;
    int len = 0;
    while(temp!=NULL){
        ++len;
        temp = temp->next;
    }
    if(len == 1) return head=NULL;
    n = (len - n) + 1;
    temp = head;
    while(temp!=NULL){
        ++c;
        if(c == n){
            if(tail!=NULL) tail->next = temp->next;
            else {
                tail = temp->next;
                head = tail;
            }
            temp->next = NULL;
            temp = tail->next;
        }else{
            tail = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main(void){
    string s;
    getline(cin, s);
    int n; cin>>n;
    cin.ignore();
    istringstream ss(s);
    int val;
    ListNode* temp = head = new ListNode(-1);
    while(ss>>val){
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    ListNode* ans = removeNthFromEnd(head->next, n);
    while (ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    
}
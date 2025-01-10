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

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    ListNode* temp = head;
    ListNode* tail = NULL;
    int len = 0;
    while(temp!=NULL){
        ++len;
        temp = temp->next;
    }
    if(len == 1 && head->val == val) return head = NULL;
    temp = head;
    while(temp!=NULL){
        if(temp->val == val){
            ListNode* temp2 = temp;
            while(temp2 && temp2->val == val) temp2 = temp2->next;
            if(tail!=NULL){
                if(temp2!=NULL) temp = tail->next = temp2;
                else temp = tail->next = NULL;
            }else{
                if(temp2!=NULL) head = temp = temp2;
                else temp = head = NULL; 
            }
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
    ListNode* ans = removeElements(head->next, n);
    while (ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    
}
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){}
    ListNode(int val):val(val){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};

ListNode* head;

ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        reverse(v.begin(),v.end());
        ListNode* head2 = new ListNode();
        temp = head2;
        for(int i=0;i<v.size();++i){
            temp->val = v[i];
            temp->next = new ListNode();
            if(i!=(v.size()-1)) temp = temp->next;
        }
        temp->next = NULL;
        return head2;
}

int main(void){
    int i=1;
    head = new ListNode(i);
    ListNode* temp = NULL;
    temp = head;
    while(++i<=10){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode* head2 = reverseList(head);
    temp = head2;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
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

bool hasCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return false;
    ListNode* tor = head;
    ListNode* hair = head->next;
    while(tor!=hair){
        if(hair->next==NULL || hair->next->next==NULL) return false;
        hair=hair->next->next;
        tor=tor->next;
    }
    return true;
}

int main(void){
    head = new ListNode();
    ListNode* temp = NULL;
    temp = head;
    int n;
    while(cin>>n){
        if(n==-1) break;
        temp->val = n;
        temp->next = new ListNode();
        temp = temp->next;
    }
    if(hasCycle(head)) cout<<"true\n";
    else cout<<"false\n";
}
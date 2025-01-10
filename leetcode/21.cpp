#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next = NULL;
    ListNode(){}
    ListNode(int val):val(val){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};

ListNode* head1, *head2;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL) return list1;
        ListNode* m=new ListNode(-1);
        ListNode* mt=m;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                mt->val = temp1->val;
                temp1=temp1->next;
            }else{
                mt->val = temp2->val;
                temp2=temp2->next;
            }
            mt = mt->next = new ListNode(-1);
        }
        if(temp1!=NULL){
           while(temp1!=NULL){
                mt->val = temp1->val;
                if(temp1->next!=NULL)
                    mt = mt->next = new ListNode(-1);
                temp1=temp1->next;
            }
        }
        if(temp2!=NULL){
            while(temp2!=NULL){
                mt->val = temp2->val;
                if(temp2->next!=NULL)
                    mt = mt->next = new ListNode(-1);
                temp2=temp2->next;
            }
        }
        return m;
}

int main(void){
    int n1,n2;cin>>n1>>n2;
    head1 = new ListNode();
    head2 = new ListNode();
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    vector<int> v1(n1, 0);
    vector<int> v2(n2, 0);
    for(int i=0;i<n1;++i) cin>>v1[i];
    for(int i=0;i<n2;++i) cin>>v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i=0;i<n1;++i){
        temp1->val=v1[i];
        if(i!=n1-1) temp1 = temp1->next = new ListNode();
    }
    for(int i=0;i<n2;++i){
        temp2->val=v2[i];
        if(i!=n2-1) temp2 = temp2->next = new ListNode();
    }
    ListNode* merged = mergeTwoLists(head1, head2);
    temp1 = merged;
    while (temp1!=NULL)
    {
        cout<<temp1->val<<" ";
        temp1 = temp1->next;
    }
    
}
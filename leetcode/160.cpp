#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *t1 = headA, *t2 = headB;

    while(t1 != t2) {
        t1 = t1 ? t1->next : headA;
        t2 = t2 ? t2->next : headB;
    }
    return t1;
}

int main(void) {
    
}
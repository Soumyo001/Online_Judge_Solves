#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode* next = NULL;
    ListNode(){}
    ListNode(int val):val(val){}
    ListNode(int val, ListNode* next):val(val),next(next){}
};

ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        if(l1==NULL && l2==NULL) return l1;
        ListNode* m=new ListNode(-1);
        ListNode* mt=m;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
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

ListNode* devideAndConquare(vector<ListNode*>& lists, int left, int right){
    if(left == right) return lists[left];
    int mid = (left+right)>>1;
    ListNode* l = devideAndConquare(lists, left, mid);
    ListNode* r = devideAndConquare(lists, mid+1, right);
    return mergeTwoList(l, r);
}

ListNode* mergeKLists3(vector<ListNode*>& lists){  // most optimized solution
    if(lists.empty()) return NULL;
    return devideAndConquare(lists, 0, lists.size()-1);
}


ListNode* mergeKLists2(vector<ListNode*>& lists){  // solution 2
    if(lists.empty()) return NULL;
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    for(int i=0;i<lists.size();++i) if(lists[i]!=NULL) pq.push({lists[i]->val, lists[i]});
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    while (!pq.empty())
    {
        const pair<int, ListNode*> n = pq.top(); pq.pop();
        temp->next = new ListNode(-1);
        if(n.second->next!=NULL){
            pq.push({n.second->next->val, n.second->next});
        }
        temp->next->val = n.first;
	    temp = temp->next;
    }
    return ans->next;
}


ListNode* mergeKLists(vector<ListNode*>& lists) {   // naive solution
    if(lists.empty()) return NULL;
    int c = 0;
    for(int i=0;i<lists.size();++i) if(lists[i]==NULL) ++c;
    if(c==lists.size()) return NULL;
    vector<int> v;
    for(int i=0;i<lists.size();++i){
        while(lists[i]!=NULL){
            v.push_back(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    sort(v.begin(),v.end());
    ListNode* ans = new ListNode(-1);
    ListNode* temp = ans;
    for(int i=0;i<v.size();++i){
        temp->val = v[i];
        if(i!=v.size()-1) temp = temp->next = new ListNode(-1);
    }
    return ans;
}

int main(void){
    vector<ListNode*> v;
    int n;cin>>n;
    cin.ignore();
    for(int i=0;i<n;++i){
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        string s; getline(cin, s);
        istringstream ss(s);
        int val;
        vector<int> vi;
        while(ss>>val) vi.push_back(val);
        for(int j=0;j<vi.size();++j){
            temp->val = vi[j];
            if(j!=vi.size()-1) temp = temp->next = new ListNode(-1);
        }
        v.push_back(head);
    }

    ListNode* ans = mergeKLists3(v);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
}

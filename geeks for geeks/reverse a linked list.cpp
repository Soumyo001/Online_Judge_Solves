#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:

    struct Node* reverseList(struct Node* head) {
        if(head==NULL) return head;
        Node* temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        reverse(v.begin(),v.end());
        Node* head2 = new Node(v[0]);
        temp = head2;
        for(int i=0;i<v.size();++i){
            temp->data = v[i];
            temp->next = new Node(-1);
            if(i!=(v.size()-1)) temp = temp->next;
        }
        temp->next = NULL;
        return head2;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int T=1, n, l, firstdata;
    // cin >> T;
    cin.ignore();
    while (T--) {
        struct Node *head = NULL, *tail = NULL;

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int index = 0;
        n = arr.size();
        if (n != 0) {

            head = new Node(arr[0]);
            tail = head;
        }

        for (int i = 1; i < n; i++) {
            l = arr[i];
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        head = ob.reverseList(head);

        printList(head);
    }
    return 0;
}
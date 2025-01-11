#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> m;
    stack<int> st;
    vector<int> idx(nums2.size(), 0);
    vector<int> ans(nums1.size(), 0);
    for(int i=0; i<nums2.size(); ++i) m[nums2[i]] = i;

    for(int i=0;i<nums2.size();++i){
        while (!st.empty() && nums2[st.top()]<nums2[i])
        {
            idx[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {idx[st.top()] = -1; st.pop();}
    
    for(int i=0;i<nums1.size();++i){
        ans[i] = idx[m[nums1[i]]] == -1? -1:nums2[idx[m[nums1[i]]]];
    }
    return ans;
}

int main(void){
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    cin.ignore();
    istringstream ss(s1);
    istringstream ss2(s2);
    int val;
    vector<int> a,b;
    while(ss>>val) a.push_back(val);
    while(ss2>>val) b.push_back(val);
    vector<int> nge = nextGreaterElement(a,b);
    for(const auto i : nge) cout<<i<<" ";
}
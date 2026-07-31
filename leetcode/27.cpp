#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    vector<int> v;
    for(const int i : nums) {
        if(i != val) v.push_back(i);
    }
    nums = v;
    return nums.size();
}

int main(void) {
    int n;cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<removeElement(v, 5);
}
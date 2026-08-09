#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int x = nums.size()/2;
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); ++i) ++m[nums[i]];
    for(const pair<int,int>& i: m) if(i.second > x) return i.first;
    return -1;
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<majorityElement(v);
}
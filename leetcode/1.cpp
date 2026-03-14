#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    if(nums.empty()) return {};

    unordered_map<int,int> m;

    for(int i=0; i<nums.size(); ++i) {
        int left = target - nums[i];
        if(m.find(left) != m.end()) {
            return {m[left], i};
        }
        m[nums[i]] = i;
    }
    return {};
}

int main(void) {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i) cin>>nums[i];
    int target; cin >> target;
    for(const int i: twoSum(nums, target)) cout<<i<<" ";
    cout<<"\n";
}
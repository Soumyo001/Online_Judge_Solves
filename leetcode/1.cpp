#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i) {
        if(m.find(target - nums[i]) != m.end()) return {i, m[target - nums[i]]};
        m[nums[i]] = i;
    }
    return {-1, -1};
}

int main(void) {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;++i) cin>>nums[i];
    int target; cin >> target;
    for(const int i: twoSum(nums, target)) cout<<i<<" ";
    cout<<"\n";
}
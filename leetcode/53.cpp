#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return 0;
    int currentSum = nums[0];
    int maxSum = nums[0];

    for(int i=1;i<nums.size();++i) {
        currentSum = max(nums[i], currentSum+nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(void) {
    int n; cin >> n; vector<int> v(n); for(int i=0;i<n;++i) cin>>v[i];
    cout<<maxSubArray(v)<<"\n";
}
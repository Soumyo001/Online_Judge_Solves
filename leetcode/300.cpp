#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> ans;
    for(int i=0; i<nums.size(); ++i) {
        if(ans.empty() || ans[ans.size() - 1] < nums[i]) {
            ans.push_back(nums[i]);
        } else {
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            *it = nums[i];
        }
    }
    return ans.size();
}

int main(void) {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    cout<<lengthOfLIS(v)<<"\n";
}
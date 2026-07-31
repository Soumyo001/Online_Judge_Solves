#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        if(nums[mid] == target) return mid;
        if(target < nums[mid]) hi = mid - 1;
        if(nums[mid] < target) lo = mid + 1;
    }
    return lo;
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    sort(v.begin(), v.end());
    cout<<searchInsert(v, 5);
}
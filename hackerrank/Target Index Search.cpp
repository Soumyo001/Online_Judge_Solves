#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int target) {
    for(int i = 0; i < nums.size(); ++i) if(nums[i] == target) return i;
    return -1;
}

int main(void) {
    int n, t; cin >> n >> t; vector<int> v(n, 0); for(int i=0; i < n; ++i) cin >> v[i];
    cout<<binarySearch(v, t);
}
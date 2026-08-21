#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int left = 0;
    for(int right = 0; right < nums.size(); ++right) {
        if(nums[right] != 0) {
            swap(nums[left], nums[right]);
            ++left;
        }
    }
}

int main(void) {
    int n; cin >> n; vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    moveZeroes(v);
    for(const int i : v) cout<<i<<" ";
}
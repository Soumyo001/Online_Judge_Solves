#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n-1;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int cap = 0;

    while(left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if(leftMax <= rightMax) {
            cap += (leftMax - height[left]);
            ++left;
        } else {
            cap += (rightMax - height[right]);
            --right;
        }
    }
    return cap;
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    cout<<trap(v)<<"\n";
}
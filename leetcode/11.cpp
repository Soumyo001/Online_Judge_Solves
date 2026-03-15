#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int max_cap = INT_MIN;
    while(left < right) {
        max_cap = max(max_cap, min(height[left], height[right]) * (right-left));
        if(height[left] >= height[right]) --right;
        else ++left;
    }
    return max_cap;
}

int main(void) {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    cout<<maxArea(v)<<"\n";
}
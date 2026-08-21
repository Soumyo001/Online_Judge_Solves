#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxSize = 0;
    while(left < right) {
        int dist = right - left;
        int h = min(height[left], height[right]);
        maxSize = max(maxSize, h*dist);
        if(height[left] <= height[right]) ++left;
        else --right;
    }
    return maxSize;
}

int main(void) {
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    cout<<maxArea(v)<<"\n";
}
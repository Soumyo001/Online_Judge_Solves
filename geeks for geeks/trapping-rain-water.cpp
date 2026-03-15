#include <bits/stdc++.h>
using namespace std;

int maxWater(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n-1;
    int leftMax = INT_MIN;
    int rightMax = INT_MIN;
    int cap = 0;

    while(left < right) {
        leftMax = max(leftMax, arr[left]);
        rightMax = max(rightMax, arr[right]);

        if(leftMax <= rightMax) {
            cap += (leftMax - arr[left]);
            ++left;
        } else {
            cap += (rightMax - arr[right]);
            --right;
        }
    }
    return cap;
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin >> v[i];
    cout<<maxWater(v)<<"\n";
}
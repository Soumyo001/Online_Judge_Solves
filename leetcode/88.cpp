#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=0; i<n; ++i) nums1[m + i] = nums2[i];
    sort(nums1.begin(), nums1.end());
}

int main(void) {
    int n, m;
    cin>>n>>m;
    vector<int> v1(m+n, 0),v2(n);
    for(int i=0; i<m; ++i) cin>>v1[i];
    for(int i=0; i<n; ++i) cin>>v2[i];
    merge(v1,m,v2,n);
}
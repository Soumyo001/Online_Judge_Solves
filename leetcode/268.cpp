#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int tot = (n*(n+1))/2;
    int sum = 0;
    for(const int i : nums) sum += i;
    return tot - sum;
}

int main(void) {
    int n;cin >> n; vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<missingNumber(v);
}
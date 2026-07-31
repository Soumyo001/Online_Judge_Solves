#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {

    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}

int main(void) {
    int n;cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<removeDuplicates(v)<<"\n";
}
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;
    for(int i: nums) {
        ++m[i];
    }
    for(auto i: m) if(i.second == 1) return i.first;
    return -1;
}

int main(void) {
    int n;cin>>n;vector<int> v(n, 0);for(int i=0;i<n;++i) cin>>v[i];
    cout<<singleNumber(v);
}
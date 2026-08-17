#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> m;
    for(const int i : nums) {++m[i]; if(m[i] > 1) return true;}
    return false;
}

int main(void) {
    int n; cin >> n; vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    cout<<containsDuplicate(v);
}
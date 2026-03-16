#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr[0]);

    for(int i=1; i<arr.size(); ++i) {
        vector<int>& last = ans.back();
        vector<int>& curr = arr[i];

        if(curr[0] <= last[1]) last[1] = max(last[1], curr[1]);
        else ans.push_back(curr);
    }

    return ans;
}

int main(void) {
    int n; cin >> n;
    vector<vector<int>> v;
    for(int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    for(const auto& i: mergeOverlap(v)) cout<<i[0]<<" "<<i[1]<<"\n";
}
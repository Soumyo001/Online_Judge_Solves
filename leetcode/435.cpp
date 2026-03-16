#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int count = 1;
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for(int i=1; i<intervals.size(); ++i) {
        vector<int>& last =res.back();
        vector<int>& curr = intervals[i];
        if(last[1] <= curr[0]) {
            ++count;
            res.push_back(curr);
        }
    }
    return intervals.size() - count;
}

int main(void) {
    int n; cin >> n;
    vector<vector<int>> v;
    for(int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    cout<<eraseOverlapIntervals(v)<<"\n";
}
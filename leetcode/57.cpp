#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

    while(i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        ++i;
    }

    while(i < n && newInterval[1] >= intervals[i][0]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        ++i;
    }
    ans.push_back(newInterval);

    while(i < n) {
        ans.push_back(intervals[i]);
        ++i;
    }
    return ans;
}

int main(void) {
    int n; cin >> n;
    vector<vector<int>> v;
    vector<int> newV;
    for(int i=0; i<=n; ++i) {
        int a, b; cin >> a >> b;
        if(i == n) {
            newV.push_back(a);
            newV.push_back(b);
        } else {
            v.push_back({a, b});
        }
    }

    for(const vector<int>& i: insert(v, newV)) {
        cout<<i[0]<<" "<<i[1]<<"\n";
    }
}
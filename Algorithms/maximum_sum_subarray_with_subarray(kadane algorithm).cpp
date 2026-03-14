#include <bits/stdc++.h>
using namespace std;

// At index i, we ask:
// Is it better to extend the previous subarray or start a new subarray at i?

pair<int, vector<int>> kadane(vector<int>& v) {
    if(v.empty()) return {0, {}};

    int currentSum = v[0];
    int maxSum = v[0];
    int start = 0, bestL = 0, bestR = 0;
    for(int i=1; i<v.size(); ++i) {
        if(currentSum+v[i] >= v[i]) currentSum+=v[i];
        else {
            currentSum = v[i];
            start = i;
        }
        if(currentSum > maxSum) {
            maxSum = currentSum;
            bestL = start;
            bestR = i;
        }
    }
    vector<int> ans(v.begin() + bestL, v.begin() + bestR + 1);
    return {maxSum, ans};
}

int main(void) {
    //int n; cin >> n;
    vector<int> v = {-2, 3, -1, 2, -5};
    //for(int i=0;i<n; ++i) cin>>v[i];
    pair<int, vector<int>> ans = kadane(v);
    cout<<ans.first<<"\nlength: "<<ans.second.size()<<"\n";
    for(const int i: ans.second) cout<<i<<" ";
    cout<<"\n";
}
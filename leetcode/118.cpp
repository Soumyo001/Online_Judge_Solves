#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for(int i=0; i<numRows; ++i) {
        vector<int> v(i+1, 1);
        for(int j=1; j<i; ++j) {
            v[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(v);
    }

    return ans;
}

int main(void) {
    int n; cin >> n;
    const auto& v = generate(n);
    for(const auto& i: v) {
        for(const auto j: i) cout<<j<<" ";
        cout<<"\n";
    }
}
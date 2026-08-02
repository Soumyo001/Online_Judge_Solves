#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans;

    for(int i=0; i<=rowIndex; ++i) {
        vector<int> v(i+1, 1);
        for(int j=1; j<i; ++j) {
            v[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans.push_back(v);
    }

    return ans.back();
}

int main(void) {
    int n; cin >> n;
    for(int i: getRow(n)) cout<<i<<" ";
}
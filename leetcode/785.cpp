#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int vertex,vector<vector<int>>& graph,vector<int>& m,int c) {
        m[vertex] = c;
        bool isBi = true;
        for(const int i : graph[vertex]) {
            if(m[i] == m[vertex]) return false;
            if(m[i] != -1) continue;
            isBi &= dfs(i,graph,m,!c);
        }
        return isBi;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> m(n, -1);
        bool ans = true;
        for(int i=0; i<n; ++i) {
            if(m[i] == -1) ans = ans & dfs(i,graph,m,0);
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << s.isBipartite(graph) << endl;
    return 0;
}
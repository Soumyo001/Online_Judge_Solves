#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int idx = -1;
        int c = 0;
        bool is = true;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<m;++i){
            c = 0;
            is = true;
            if(mat[i][i]==0){
                for(int j=0;j<n;++j){
                    if(mat[j][i] == 1) ++c;
                }
                for(int j=0;j<m;++j) if(mat[i][j] == 1) is = false;
                if(c == n-1 && is){
                    idx = i;
                    break;
                }
            }
        }
        return idx;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}
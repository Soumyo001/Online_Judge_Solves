#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoRepeated(int n, int arr[]) {
        unordered_map<int, int> f;
        vector<int> v;
        for(int i=0;i<n+2;++i) {
            if(f.find(arr[i])!=f.end())
                v.push_back(arr[i]);
            else ++f[arr[i]];
        }
        
        return v;
    }
};

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        int arr[n + 2];

        for (int i = 0; i < n + 2; i++)
            cin >> arr[i];

        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(n, arr);
        cout << res[0] << " " << res[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
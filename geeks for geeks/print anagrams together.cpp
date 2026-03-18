#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> res;
        vector<vector<string>> ans;
        for(const string s: arr) {
            string k = s;
            sort(k.begin(), k.end());
            res[k].push_back(s);
        }
        for(const auto& it: res) ans.push_back(it.second);
        return ans;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        istringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);
        for(const vector<string>& i: result) {
            for(const string s: i) cout<<s<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
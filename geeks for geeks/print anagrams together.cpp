#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAnagram(string s1,string s2){
        if(s1.length()!=s2.length()) return false;
        bool is = true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.length();++i) if(s1[i]!=s2[i]){
            is=false;
            break;
        }
        return is;
    }
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        vector<bool> vis(arr.size(),false);
        for(int i=0;i<arr.size();++i){
            if(!vis[i]){
                vector<string> a;
                for(int j=i;j<arr.size();++j){
                    if(isAnagram(arr[i],arr[j])){
                        a.push_back(arr[j]);
                        vis[j]=true;
                    }
                }
                ans.push_back(a);
            }
        }
        vector<string> a;
        for(int i=0;i<arr.size();++i) if(!vis[i]) a.push_back(arr[i]);
        if(!a.empty()) ans.push_back(a);
        return ans;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    cin.ignore();
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
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
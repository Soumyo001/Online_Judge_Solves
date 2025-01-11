#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> s;
        vector<int> ans(arr.size(), 0);
        for(int i=0;i<arr.size();++i){
            while (!s.empty() && arr[s.top()]<arr[i])
            {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            ans[s.top()] = -1;
            s.pop();
        }
        vector<int> mans(arr.size(), 0);
        for(int i=0;i<ans.size();++i) mans[i] = ans[i]==-1? -1:arr[ans[i]];
        return mans;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
    }

    return 0;
}
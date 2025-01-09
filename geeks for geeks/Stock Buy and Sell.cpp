#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int mini = prices[0];
        int result = 0;
        for(int i=0;i<prices.size();++i){
            mini = min(mini, prices[i]);
            result = max(result, prices[i] - mini);
        }
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}
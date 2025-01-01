#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long> productExceptSelf(vector<int>& arr) {
        vector<long long> left(arr.size(), 1), right(arr.size(), 1), ans(arr.size(), 1);
        for(int i=1;i<arr.size();++i) left[i] = left[i-1]*arr[i-1]*1LL;
        for(int j=arr.size()-2;j>=0;--j) right[j] = right[j+1]*arr[j+1]*1LL;
        for(int i=0;i<arr.size();++i) ans[i]=left[i]*right[i]*1LL;
        return ans;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<long long> vec = obj.productExceptSelf(arr);

        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}
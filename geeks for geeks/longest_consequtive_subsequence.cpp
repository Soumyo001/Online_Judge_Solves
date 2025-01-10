#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        queue<int> q;
        int src = arr[0];
        unordered_map<int, int> graph;
        for(int i=0;i<arr.size()-1;++i) graph[arr[i]] = arr[i+1];
        //for(auto& i:graph) cout<<i.first<<" "<<i.second<<"\n";
        graph[arr[arr.size()-1]] = -1;
        q.push(src);
        int c = 1, ct=0, n=src;
        while(graph[n]!=-1){
            n = q.front();
            q.pop();
            ++ct;
            if(graph[n]!=n+1){
                c = max(c, ct);
                ct = 0;
            }
           
            q.push(graph[n]);
        }
        return c;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl;
    }
    return 0;
}
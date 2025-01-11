#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void deleteMid(stack<int>& s) {
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        for(int i=0;i<v.size();++i){
            if(i == v.size()/2) v.erase(v.begin()+i,v.begin()+i+1);
        }
        reverse(v.begin(),v.end());
        for(const auto i : v) s.push(i);
    }
};

int main() {
    int t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}
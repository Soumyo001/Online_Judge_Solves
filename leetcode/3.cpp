#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int mx = 0, left = 0;

    for(int right = 0; right < s.length(); ++right) {
        while(window.count(s[right])) {
            window.erase(s[left]);
            ++left;
        }

        window.insert(s[right]);
        mx = max(mx, right - left + 1);
    }
    return mx;
}

int main(void){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<"\n";
}
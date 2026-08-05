#include <bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int cnt = 0;
    int idx = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
    for(const vector<string>& v: items) {
        if(v[idx] == ruleValue) ++cnt;
    }
    return cnt;
}

int main(void) {
    
}
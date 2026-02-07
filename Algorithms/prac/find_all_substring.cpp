#include <bits/stdc++.h>
using namespace std;

void substringRecur(string s, int n, int index, string& curr, vector<string>& res){
    if(index == n) return;

    curr.push_back(s[index]);
    res.push_back(curr);

    substringRecur(s, n, index + 1, curr, res);

    curr.pop_back();

    if(curr.empty()){
        substringRecur(s, n, index + 1, curr, res);
    }
}

vector<string> findAllSubStringRecur(string s){
    string curr = "";
    vector<string> res;
    substringRecur(s, s.length(), 0, curr, res);
    return res;
}

vector<string> findAllSubStringIter(string s){
    vector<string> res;

    for(int i = 0; i < s.length(); ++i)
        for(int j = i; j < s.length(); ++j)
            res.push_back(s.substr(i, j - i + 1));
    return res;
}

int main(void){
    string s;
    getline(cin, s);
    vector<string> v = findAllSubStringRecur(s);
    vector<string> v1 = findAllSubStringIter(s);

    for(const auto& i: v) cout<<i<<" ";
    cout<<"\n";
    for(const auto& i:v1) cout<<i<<" ";
    cout<<"\n"<<"is both method same : "<<(v == v1?"true":"false")<<"\n\n";
}

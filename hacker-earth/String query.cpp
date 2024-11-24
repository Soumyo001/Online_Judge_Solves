#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;int m;cin>>s>>m;
    unordered_map<char,vector<int>> pos;
    for(int i=0;i<s.length();++i){
        pos[s[i]].push_back(i);
    }

    vector<bool> dlt(s.length(),false);
    for(int i=0;i<m;++i){
        int k;char x;cin>>k>>x;
        dlt[pos[x][k-1]]=true;
        pos[x].erase(pos[x].begin()+(k-1));
    }

    string result="";
    for(int i=0;i<s.length();++i){
        if(!dlt[i]){
            result.push_back(s[i]);
        }
    }
    cout<<result;
}
#include<bits/stdc++.h>
using namespace std;

struct QUERY
{
    int a; char c;
};

vector<QUERY> queries;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;int q;
    cin>>s>>q;
    //cout<<s.length()<<endl;
    unordered_map<char,vector<int>> positions;
    vector<bool> to_delete(s.length(),false);
    for(int i=0;i<s.length();++i) positions[s[i]].push_back(i);
    while(q--){
        int k; char c;
        cin>>k>>c;
        queries.push_back({k,c});
        // to_delete[positions[c][k-1]]=true;
        // positions[c].erase(positions[c].begin()+(k-1));
    }
    sort(queries.begin(),queries.end(),[&](const QUERY& a, const QUERY& b){
        return a.a<b.a;
    });
    for(auto& query:queries){
        
    }
    string result = "";
    for(int i=0;i<s.length();++i){
        if(!to_delete[i]) result+=s[i];
    }
    cout<<result;
}
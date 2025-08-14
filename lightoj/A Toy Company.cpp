#include <bits/stdc++.h>
using namespace std;

struct Node{
    string word;
    int dist = 0;
};

char nextChar(char c){
    return (c == 'z'? 'a':c+1);
}

char prevChar(char c){
    return (c == 'a'? 'z':c-1);
}

vector<string> neighbour(string s){
    vector<string> res;
    string temp = s;
    for(int i=0;i<3;++i){
        temp[i] = nextChar(temp[i]);
        res.push_back(temp);
        temp = s;
        temp[i] = prevChar(temp[i]);
        res.push_back(temp);
    }
    return res;
}

int bfs(string start, string end, unordered_set<string>& constraints){
    if(constraints.count(start) || constraints.count(end)) return -1;
    if(start == end) return 0;
    queue<Node> q;
    unordered_set<string> vis;
    q.push({start, 0});
    vis.insert(start);
    while (!q.empty())
    {
        Node n = q.front();q.pop();
        for(const string child : neighbour(n.word)){
            if(!vis.count(child) && !constraints.count(child)){
                if(child == end) return n.dist+1;
                q.push({child, n.dist+1});
                vis.insert(child);
            }
        }
    }
    return -1;
}

void solve(int t){
    string start,end;cin>>start>>end;
    int n;cin>>n;
    unordered_set<string> constriants;
    for(int i=0;i<n;++i){
        string a, b, c; cin>>a>>b>>c;
        for(char x:a) for(char y:b) for(char z:c) constriants.insert({x,y,z});  
    }
    cout<<"Case "<<t<<": "<<bfs(start,end,constriants)<<"\n";
}

int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;++i) solve(i);
}
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0,  0, 1,  1, -1, -1 };
int dy[] = {0,  0, 1, -1, 1, -1,  1, -1 };

bool isValid(int x, int y, int r, int c){
    return y<r && x<c && x>=0 && y>=0;
}

set<pair<int,int>> findStringInGrid(vector<vector<char>>& v, string s, vector<pair<int,int>>& pos){
    set<pair<int,int>> ans;
    int n = v.size();
    int m = v[0].size();
    for(const auto& p:pos){
        for(int i=0;i<8;++i){
            int nx = p.second+dx[i];
            int ny = p.first+dy[i];
            
            bool found =true;
            for(int j=1;j<s.length();++j){
                if(!isValid(nx,ny,n,m) || s[j]!=v[ny][nx])
                {
                    found = false;
                    break;
                }
                nx+=dx[i];
                ny+=dy[i];
            }
            if(found) ans.insert({p.first, p.second});
            
        }
    }
    return ans;
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) cin>>v[i][j];
    string s;cin>>s;
    vector<pair<int,int>> pos;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) if(v[i][j]==s[0]) pos.push_back({i,j});
    
    set<pair<int,int>> ans = findStringInGrid(v, s, pos);
    for(auto& i:ans) cout<<i.first<<" "<<i.second<<"\n";
}
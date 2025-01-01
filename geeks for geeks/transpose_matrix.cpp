#include <bits/stdc++.h>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& v){
    std::vector<std::vector<int>> ans(v.size(), std::vector<int>(v[0].size(),0));
    for(int i=0;i<v.size();++i){
        for(int j=0;j<v[0].size();++j){
            ans[j][i]=v[i][j];
        }
    }
    return ans;
}

int main(void){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> v(n,std::vector<int>(m,0));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) std::cin>>v[i][j];
    std::vector<std::vector<int>> ans = transpose(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for(int j=0;j<ans[i].size();++j) std::cout<<ans[i][j]<<" ";
        std::cout<<"\n";
    }
    
}
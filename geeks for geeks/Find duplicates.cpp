#include <bits/stdc++.h>

void solve(){
    int n;
    std::cin>>n;
    std::unordered_map<int,int> f;
    std::vector<int> v(n, 0);
    std::vector<int> ans;
    for(int i=0;i<n;++i){
        std::cin>>v[i];
        // if(f.find(v[i])!=f.end())
        //     ans.push_back(v[i]);
        // else ++f[v[i]];
        ++f[v[i]];
    }
    for(const auto& i : f){
        if(i.second > 1) ans.push_back(i.first);
    }
    reverse(ans.begin(), ans.end());
    for(const auto& i: ans) std::cout<<i<<" ";
}

int main(void){
    solve();
}
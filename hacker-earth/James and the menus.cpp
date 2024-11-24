#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool hasDuplicate(unordered_map<int,int> ct){
    unordered_set<int> seen,duplicate;
    for(const auto& i:ct){
        if(!seen.insert(i.second).second){
            return true;
        }
    }
    return false;
}

void solve(){
    int n,m;cin>>n>>m;
    ll arr[n+1][m+1];
    memset(arr,0,sizeof(arr));
    unordered_map<int,int> ct;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j){
            cin>>arr[i][j];
            arr[i][0]+=arr[i][j];
        }
    }

    for(int i=1;i<=m;++i){
        vector<int> menu_index;
        ll mx=INT_MIN;

        for(int j=1;j<=n;++j){
            if(mx<arr[j][i]){
                mx=arr[j][i];
                menu_index.clear();
                menu_index.push_back(j);
            }else if(mx==arr[j][i]){
                menu_index.push_back(j);
            }
        }
        for(auto& i:menu_index)
            ++ct[i];  
    }
    int idx=-1;
    if(!hasDuplicate(ct)){
        int mx=INT_MIN;
        for(const auto& i:ct){
            if(mx<i.second){
                mx=i.second;
                idx=i.first;
            }
        }
        cout<<idx;
    }else{
        double d;
        double mx=-1.f;
        int mxgpc=INT_MIN;
        for(const auto& i:ct){
            d=arr[i.first][0]/(m*1.0);
            if(mxgpc<i.second){
                mxgpc=i.second;
                mx=d;
                idx=i.first;
            }else if(mxgpc==i.second && d>mx){
                mx=d;
                idx=i.first;
            }
        }
        cout<<idx;
    }


}

int main(void){
    solve();
}
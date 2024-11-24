#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;++i) cin>>v[i];

    int from = 0, to = 0;
    bool flag=false;
    for(int i=0;i<n;++i){
        if(!(v[i]&1) && !flag){
            from = i;
            flag=true;
        }else if((v[i]&1) && flag){
            to = i;
            reverse(v.begin()+from,v.begin()+to);
            flag=false;
        }else if(flag && i==(n-1) && !(v[i]&1)){
            to=i+1;
            reverse(v.begin()+from,v.begin()+to);
            flag=false;
        }
    }

    for(auto& i:v) cout<<i<<" ";
}
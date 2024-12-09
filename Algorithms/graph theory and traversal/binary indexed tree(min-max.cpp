#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int BIT[N],arr[N],n;
void update(int idx,int val){
    while(idx<=n){
        BIT[idx]=min(BIT[idx],val);
        idx=idx+(idx& -idx);
    }
}
int query(int idx){
    int val=INT_MAX;
    while(idx>0){
        val=min(val,BIT[idx]);
        idx=idx-(idx& -idx);
    }
    return val;
}
int main(void){
    memset(BIT,1e9+10,sizeof(BIT));
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        update(i,arr[i]);
    }
    while(true){
        int type;cin>>type;
        if(type==1){
            int idx,val;cin>>idx>>val;
            arr[idx]=val;
            update(idx,val);
        }else if(type==2){
            int idx;cin>>idx;
            cout<<query(idx)<<'\n';
        }else break;
    }
}
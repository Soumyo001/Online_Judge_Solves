#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int BIT[N],arr[N],n;

void update(int idx,int val){
    while(idx<=n){
        BIT[idx]+=val;
        idx=idx+(idx&-idx);
    }
}

int sum(int idx){
    int d=0;
    while(idx>0){
        d+=BIT[idx];
        idx=idx-(idx&-idx);
    }
    return d;
}

int main(void){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        update(i,arr[i]&1);
    }
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==0){
            int x,y;cin>>x>>y;
            update(x,(y&1? arr[x]&1?0:1 : arr[x]&1?-1:0));
            arr[x]=y;
        }else if(type==1){
            int l,r;cin>>l>>r;
            cout<<(r-l+1)-(sum(r)-sum(l-1))<<endl;
        }else if(type==2){
            int l,r;cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
    }
}
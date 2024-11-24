#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll BIT[N][N][N];
int n,q;
void update(int x,int y,int z,int val){
    for(int i=x;i<=n;i+=(i&-i)){
        for(int j=y;j<=n;j+=(j&-j)){
            for(int k=z;k<=n;k+=(k&-k)){
                BIT[i][j][k]+=(val*1LL);
            }
        }
    }
}
ll sum(int x,int y,int z){
    ll sum=0;
    for(int i=x;i>0;i-=(i&-i)){
        for(int j=y;j>0;j-=(j&-j)){
            for(int k=z;k>0;k-=(k&-k)){
                sum+=BIT[i][j][k];
            }
        }
    }
    return sum;
}
int main(void){
    cin>>n>>q;++n;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int x,y,z,val;cin>>x>>y>>z>>val;
            ++x;++y;++z;
            update(x,y,z,val);
        }else{
            int x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
            ++x1;++y1;++z1;++x2;++y2;++z2;
            cout<<sum(n,n,n)-(sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)
            +sum(x1-1,y1-1,z2)+sum(x2,y1-1,z1-1)+sum(x1-1,y2,z1-1)-sum(x1-1,y1-1,z1-1))<<'\n';
        }
    }
}
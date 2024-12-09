#include<bits/stdc++.h>
#define ll int
using namespace std;
const int N=1e2+5;
ll BIT[N][N][N];
void update(int x,int y,int z,ll val){
    for(int i=x;i<=N;i+=(i&-i)){
        for(int j=y;j<=N;j+=(j&-j)){
            for(int k=z;k<=N;k+=(k&-k)){
                BIT[i][j][k]+=val;
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
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==1){
            int x,y,z,val;cin>>x>>y>>z>>val;
            ++x;++y;++z;update(x,y,z,val);
        }else{
            int x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
            ++x1;++x2;++y1;++y2;++z1;++z2;
            cout<<sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)
            +sum(x1-1,y1-1,z2)+sum(x2,y1-1,z1-1)+sum(x1-1,y2,z1-1)-sum(x1-1,y1-1,z1-1)<<'\n';
        }
    }
}

/*
input :
13
1 3 4 5 10
1 3 4 6 20
1 3 5 6 30
2 3 4 5 3 5 6
1 3 4 6 -10
2 3 4 5 3 5 6
1 4 6 8 50
2 3 4 5 4 6 8
1 50 80 100 100
2 4 8 9 50 90 101
2 50 60 70 50 80 99
1 17 15 16 20
2 17 13 12 17 15 16

output :

60
50
100
100
0
20

 */
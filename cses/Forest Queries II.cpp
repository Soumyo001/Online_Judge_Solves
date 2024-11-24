#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int BIT[N][N];
char forest[N][N];
int n,q;
void update(int y,int x,int val){
    for(int i=y;i<=n;i+=(i&-i)){
        for(int j=x;j<=n;j+=(j&-j)){
            BIT[i][j]+=val;
        }
    }
}
int sum(int y,int x){
    int sum=0;
    for(int i= y; i>0; i-=(i&-i)){
        for(int j= x; j>0; j-=(j&-j)){
            sum+=BIT[i][j];
        }
    }
    return sum;
}
void inputGrid(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>forest[i][j];
            if(forest[i][j]=='*'){
                update(i,j,1);
            }
        }
    }
}
void change_state(int y,int x){
    if(forest[y][x]=='*'){
        forest[y][x]='.';
        update(y,x,-1);
    }else{
        forest[y][x]='*';
        update(y,x,1);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    inputGrid();
    while(q--){
        int type;cin>>type;
        if(type==1){
            int y,x;cin>>y>>x;
            change_state(y,x);
        }else{
            int y1,x1,y2,x2;cin>>y1>>x1>>y2>>x2;
            cout<<sum(y2,x2)-sum(y2,x1-1)-sum(y1-1,x2)+sum(y1-1,x1-1)<<'\n';
        }
    }

}
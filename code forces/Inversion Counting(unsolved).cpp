#include<bits/stdc++.h>
using namespace std;
const int N = 1505;
int BIT[N],n;

void update(int idx,int val){
    for(idx;idx<N;idx+=(idx&-idx))
        BIT[idx]+=val;
}

int sum(int idx){
    int d=0;
    for(idx;idx>0;idx-=(idx&-idx))
        d+=BIT[idx];
    return d;
}


int main(void){
    cin>>n;
    vector<int> v;
    v.resize(n);
    int mx=INT_MIN;
    for(int i=0;i<n;++i) cin>>v[i], mx=max(mx,v[i]);
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;--l;--r;
        reverse(v.begin()+l,v.begin()+r+1);
        memset(BIT,0,sizeof(BIT));
        int inv=0;
        for(int i=0;i<n;++i){
            inv+=(sum(N-5) - sum(v[i]));
            update(v[i],1);
        }
        cout<<(inv&1? "odd":"even")<<"\n";
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int BIT[N];
ll a[N];
int n;

void update(int idx,int val){
    while(idx<=N){
        BIT[idx]+=val;
        idx=idx+(idx&-idx);
    }
}

int sum(int idx){
    int ans=0;
    while(idx>0){
        ans+=BIT[idx];
        idx=idx-(idx&-idx);
    }
    return ans;
}

int main(){
    cin>>n;
    map<ll,int> mp;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
        mp[a[i]];
    }

    int ct=1;
    for(auto& i:mp) i.second=ct++;
    for(int i=1;i<=n;++i) a[i]=mp[a[i]];
    
    int inv_ct=0;
    for(int i=1;i<=n;++i){
        inv_ct+= (sum(N)-sum(a[i]));
        update(a[i],1);
    }
    cout<<inv_ct;
}

//condition : a[i]>a[j] && i<j
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,q;
int BIT[N],arr[N];
unordered_map<int,int> last_occur;
struct QUERY{
    int l,r,idx;
    QUERY(int l,int r,int idx):l(l),r(r),idx(idx){}
};
vector<QUERY> queries;
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
void solve(){
    cin>>n>>q;
    last_occur.clear();
    queries.clear();
    vector<int> result(q+1,0);
    for(int i=0;i<=n;++i){
        arr[i]=BIT[i]=0;
    }
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    for(int idx=1;idx<=q;++idx){
        int i,j;cin>>i>>j;
        queries.push_back(QUERY(i,j,idx));
    }
    sort(queries.begin(),queries.end(),[&](const QUERY& a,const QUERY& b){
        return a.r<b.r;
    });
    int current_right=0;
    for(auto& query:queries){
        while(current_right<=query.r){
            ++current_right;
            if(last_occur.count(arr[current_right])==0){
                update(current_right,1);
                last_occur[arr[current_right]]=current_right;
            }
        }
        result[query.idx]=sum(query.r)-sum(query.l-1);
    }
    for(int i=1;i<=q;++i) cout<<result[i]<<'\n';
}
int main(void){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int test;cin>>test;
    for(int t=1;t<=test;++t){
        cout<<"Case "<<t<<":\n";
        solve();
    }
}
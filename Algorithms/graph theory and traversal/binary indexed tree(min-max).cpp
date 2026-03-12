#include<bits/stdc++.h>
using namespace std;

class BIT {
private:
    struct Tree {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
    };
    vector<Tree> bit;
    int n;
public:
    BIT(int n): n(n), bit(n+1) { }
    void update(int idx, int x) {
        while(idx <= n) {
            bit[idx].max_val = max(bit[idx].max_val, x);
            bit[idx].min_val = min(bit[idx].min_val, x);
            idx = idx + (idx & -idx);
        }
    }
    pair<int, int> query(int idx) {
        int mn = INT_MAX, mx = INT_MIN;
        while(idx > 0) {
            mx = max(mx, bit[idx].max_val);
            mn = min(mn, bit[idx].min_val);
            idx = idx - (idx & -idx);
        }
        return {mx, mn};
    }
};

int main(void){
    int n; cin>>n;
    vector<int> arr(n + 1, 0);
    BIT *bit = new BIT(n);
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        bit->update(i,arr[i]);
    }
    while(true){
        int type;cin>>type;
        if(type==1){
            int idx,val;cin>>idx>>val;
            arr[idx]=val;
            bit->update(idx,val);
        }else if(type==2){
            int idx;cin>>idx;
            pair<int, int> res = bit->query(idx);
            cout<<res.first<<" "<<res.second<<'\n';
        }else if(type==3){
            for(int i=1;i<arr.size();++i) cout<<arr[i]<<" ";
            cout<<"\n";
        }else break;
    }
}
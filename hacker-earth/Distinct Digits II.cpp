#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int N=1e5+10;
const int inf = 1e9+20;
const int ls = -1e9-20;
struct Tree{
    int maxVal=ls, maxCount=0, minVal=inf, minCount=0;

} tree[N*3];

Tree neutral_element = {0,0,inf,0};

int n,q;
long long arr[N];

int countDistinct(long long val){
    unordered_set<int> digits;
    while(val>0){
        digits.insert(val%10);
        val = val/10;
    }
    return digits.size();
}

Tree initi(int val){
    return {val,1,val,1};
}

Tree merge(const Tree& a, const Tree& b){
    int maxVal=0, maxCount=0, minVal=inf, minCount=0;
    if(a.maxVal>b.maxVal){
        maxVal = a.maxVal;
        maxCount = a.maxCount;
    }else if(a.maxVal<b.maxVal){
        maxVal = b.maxVal;
        maxCount = b.maxCount;
    }else if(a.maxVal==b.maxVal){
        maxVal=a.maxVal;
        maxCount = a.maxCount + b.maxCount;
    }

    if(a.minVal>b.minVal){
        minVal = b.minVal;
        minCount = b.minCount;
    }else if(a.minVal<b.minVal){
        minVal = a.minVal;
        minCount = a.minCount;
    }else if(a.minVal==b.minVal){
        minVal = a.minVal;
        minCount = a.minCount + b.minCount;
    }

    return {maxVal, maxCount, minVal, minCount};
}

void init(int node, int b, int e){
    if(b==e){
        tree[node] = initi(countDistinct(arr[b]));
        return;
    }
    int mid = (b+e)>>1;
    init(node<<1, b,mid);
    init((node<<1)+1,mid+1,e);
    tree[node] = merge(tree[node<<1],tree[(node<<1)+1]);
}

void update(int node, int b, int e, int i, int val){
    if(e<i || i<b) return;
    if(b>=i && e<=i){
        tree[node] = initi(countDistinct(val));
        return;
    }
    int mid = (b+e)>>1;
    update(node<<1,b,mid,i,val);
    update((node<<1)+1,mid+1,e,i,val);
    tree[node] = merge(tree[node<<1], tree[(node<<1)+1]);
}

Tree query(int node, int b, int e, int i, int j){
    if(e<i || j<b) return neutral_element;
    if(b>=i && e<=j) return tree[node];
    int mid = (b+e)>>1;
    Tree n = query(node<<1, b, mid, i, j);
    Tree m = query((node<<1)+1, mid+1, e, i, j);
    return merge(n,m);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>arr[i];
    init(1,1,n);

    cin>>q;
    while(q--){
        string s;cin>>s;
        if(s=="ADD"){
            int u,v;cin>>u>>v;
            arr[u]=(arr[u]+v)%MOD;
            update(1,1,n,u,arr[u]);

        }else if(s=="MUL"){
            int u,v;cin>>u>>v;
            arr[u]=(arr[u]*v)%MOD;
            update(1,1,n,u,arr[u]);
   
        }else if(s=="REP"){
            int u,v;cin>>u>>v;
            arr[u]=v%MOD;
            update(1,1,n,u,arr[u]);
  
        }else if(s=="MAX"){
            int u,v;cin>>u>>v;
            Tree ans = query(1,1,n,u,v);
            cout<<ans.maxVal<<" "<<ans.maxCount<<"\n";

        }else if(s=="MIN"){
            int u,v;cin>>u>>v;
            Tree ans = query(1,1,n,u,v);
           cout<<ans.minVal<<" "<<ans.minCount<<"\n";
        }
    }
}

/*

for query Type ADD: replace the uth element of the array with (uth element+v)%MOD;

for query Type MUL: replace the uth element of the array with (uth element *v)%MOD;

for query Type REP: replace uth element of the array with v%MOD

for query Type MAX: count the number of numbers which have MAXIMUM distinct digits between l to r, both inclusive

for query Type MIN: count the number of numbers which have MINIMUM distinct digits between l to r, both inclusive
*/
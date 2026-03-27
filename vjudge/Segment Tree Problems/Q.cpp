#include <bits/stdc++.h>
using namespace std;

class Sieve {
private:
    int MAXN;
    vector<bool> prime;
    void generate() {
        prime[0]=prime[1]=false;
        for(int i=2;i*i<MAXN;++i)
            if(prime[i]) 
                for(int j=i*i;j<MAXN;j+=i) prime[j]=false;
    }
public:
    Sieve(int MAXN): MAXN(MAXN) {
        prime.assign(MAXN, true);
        generate();
    }
    bool isPrime(int x) {return prime[x];}
};

class SegmentTree {
private:
    int n;
    vector<int> tree, lazy;
    Sieve& sv;
    inline int initiate(int x) {
        return sv.isPrime(x) ? 1:0;
    }
public:
    SegmentTree(int n,Sieve& sv): n(n), tree(n*4, 0), lazy(n*4, 0), sv(sv) { }
    void build(int node,int b,int e,vector<int>& arr) {
        if(b == e) {
            tree[node]=initiate(arr[b]);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=tree[left]+tree[right];
    }
    void update(int node,int b,int e,int i,int j,int x) {
        if(lazy[node]!=0) {
            tree[node]=(e-b+1)*initiate(lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }
            lazy[node]=0;
        }
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            tree[node]=(e-b+1)*initiate(x);
            if(b!=e) {
                lazy[(node<<1)]=x;
                lazy[(node<<1)+1]=x;
            }
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        update(left,b,mid,i,j,x);
        update(right,mid+1,e,i,j,x);
        tree[node]=tree[left]+tree[right];
    }
    int query(int node,int b,int e,int i,int j) {
        if(lazy[node]!=0) {
            tree[node]=(e-b+1)*initiate(lazy[node]);
            if(b!=e) {
                lazy[(node<<1)]=lazy[node];
                lazy[(node<<1)+1]=lazy[node];
            }
            lazy[node]=0;
        }
        if(e<i || j<b) return 0;
        if(b>=i && e<=j) return tree[node];
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        int p1=query(left,b,mid,i,j);
        int p2=query(right,mid+1,e,i,j);
        return p1+p2;
    }
};

void solve(Sieve& sv) {
    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    SegmentTree seg(n,sv);
    seg.build(1,0,n-1,v);
    while(q--) {
        int op;cin>>op;
        if(op == 0) {
            int x,y,v;cin>>x>>y>>v;
            seg.update(1,0,n-1,x-1,y-1,v);
        } else {
            int x,y;cin>>x>>y;
            cout<<seg.query(1,0,n-1,x-1,y-1)<<"\n";
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Sieve sv(int(1e6+10));
    int t;cin>>t;
    for(int i=1;i<=t;++i) {
        cout<<"Case "<<i<<":\n";
        solve(sv);
    }
}
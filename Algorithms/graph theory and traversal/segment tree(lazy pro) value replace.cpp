#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N],tree[N*4],lazy[N*4];
int initiate(int x) { return x; }
int merge(int a,int b) { return a+b; }
void init(int node,int b,int e) {
    if(b==e) {
        tree[node]=arr[b];
        return;
    }
    int mid=(b+e)>>1;
    int left=(node<<1);
    int right=(node<<1)+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=merge(tree[left],tree[right]);
}
void update(int node,int b,int e,int i,int j,int x) {
    if(lazy[node]!=-1) {
        tree[node]=initiate((e-b+1)*lazy[node]);
        if(b!=e) {
            lazy[(node<<1)]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }lazy[node]=-1;
    }
    if(e<i || j<b) return;
    if(b>=i && e<=j) {
        tree[node]=initiate((e-b+1)*x);
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
    tree[node]=merge(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j) {
    if(lazy[node]!=-1) {
        tree[node]=initiate((e-b+1)*lazy[node]);
        if(b!=e) {
            lazy[(node<<1)]=lazy[node];
            lazy[(node<<1)+1]=lazy[node];
        }lazy[node]=-1;
    }
    if(e<i || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)>>1;
    int left=(node<<1);
    int right=(node<<1)+1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return merge(p1,p2);
}

int main(void){
    memset(lazy,-1,sizeof(lazy));
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    init(1,0,n-1);
        while(true){
        int q;cin>>q;
        if(q==1){
            int l,r;cin>>l>>r;
            cout<<query(1,0,n-1,--l,--r)<<endl;
        }else if(q==2){
            int i,j,x;cin>>i>>j>>x;
            update(1,0,n-1,--i,--j,x);
        }else if(q==3){
            for(int i=0;i<n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }else break;
    }
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazyAdd, lazySet;
    void push(int node,int b,int e) {
        if(lazySet[node]!=-1) {
            tree[node]=((e-b+1)*lazySet[node]);
            if(b!=e) {
                lazySet[(node<<1)]=lazySet[node];
                lazySet[(node<<1)+1]=lazySet[node];
            }
            lazySet[node]=-1;
        }
        if(lazyAdd[node]!=0) {
            tree[node]+=((e-b+1)*lazyAdd[node]);
            if(b!=e) {
                lazyAdd[(node<<1)]+=lazyAdd[node];
                lazyAdd[(node<<1)+1]+=lazyAdd[node];
            }
            lazyAdd[node]=0;
        }
    }
public:
    SegmentTree(int n): n(n),tree(n*4, 0),lazyAdd(n*4, 0),lazySet(n*4, -1) { }
    void build(int node,int b,int e,vector<ll>& arr) {
        if(b == e) {
            tree[node]=arr[b];
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        build(left,b,mid,arr);
        build(right,mid+1,e,arr);
        tree[node]=tree[left]+tree[right];
    }
    void updateAdd(int node,int b,int e,int i,int j,ll x) {
        push(node,b,e);
        if(e<i || j<b) return;
        if(b>=i && e<=j) {
            lazyAdd[node]+=((e-b+1)*x);
            push(node,b,e);
            return;
        }
        int mid=(b+e)>>1;
        int left=(node<<1);
        int right=(node<<1)+1;
        updateAdd(left,b,mid,i,j,x);
        updateAdd(right,mid+1,e,i,j,x);
        tree[node]=tree[left]+tree[right];
    }
};
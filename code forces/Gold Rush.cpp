#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, int m){
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int f = q.front();q.pop();
        if(f==m) return true;
        if(f%3==0){
            q.push(f/3);
            q.push(2*f/3);
        }
    }
    return false;
}

void solve(){
    int n,m;cin>>n>>m;
    if(n<m){
        cout<<"NO\n";
        return;
    }
    if(bfs(n,m)) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
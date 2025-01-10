#include <bits/stdc++.h>
using namespace std;

void solve(){
    bool s=false,t=false;
    int n;cin>>n;
    vector<int> a(n,0);
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;++i){
        string s; cin>>s;
        int t=0;
        for(int j=0;j<s.length();++j){
            v[i][j] = s[j]-'0';
            if(v[i][j]==1) ++t;
        }
        a[i]=t;
    }
    for(int i=0;i<n-1;++i){
        if(a[i]>0 && a[i+1]>0 && a[i]!=a[i+1]) {
            t=true;
            break;
        }
    }
    cout<<(t? "TRIANGLE\n":"SQUARE\n");
    // int k=0;
    // int temp=0;
    // for(int i=0;i<n;++i){

    //     for(int j=0;j<n;++j){
    //         if(v[i][j]==1) ++k;
    //     }
    //      cout<<n<<" "<<k<<" "<<temp<<'\n';
    //     if(k==temp){
    //          s = true;
    //          t=false;
    //     }else{
    //         s=false;
    //         t=true;
    //     }
        
    //     if(k>0)
    //         temp = k;
    //     k=0;
    // }
    // if(s) cout<<"SQUARE\n";
    // else if(t) cout<<"TRIANGLE\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}
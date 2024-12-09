#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> v(n,-1);
        for(int i=0;i<n;++i) cin>>v[i];

        stack<int> st;
        bool flag=false;
        for(int i=0;i<v.size();++i){
            while(k>0 && !st.empty() && v[st.top()]<v[i]){
                st.pop();
                --k;
            }
            st.push(i);
        }
        
        while(k>0){
            --k;st.pop();
        }
        
        vector<int> results;

        while(!st.empty()){
            results.push_back(st.top());
            st.pop();
        }

        for(int i=results.size()-1;i>=0;--i){
            cout<<v[results[i]]<<" ";
        }
        cout<<'\n';
    }
}
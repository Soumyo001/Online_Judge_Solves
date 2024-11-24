#include<bits/stdc++.h>
using namespace std;
void first_fit(){
    vector<int> blocksize ({50, 200, 70, 115, 15});
    vector<int>process_size ({100, 10, 35, 15, 23, 6, 25, 55, 88, 40});
    vector<int> allocation(process_size.size(),-1);
    for(int i=0;i<process_size.size();++i){
        for(int j=0;j<blocksize.size();++j){
            if(blocksize[j]>=process_size[i]){
                allocation[i]=j;
                blocksize[j]-=process_size[i];
                break;
            }
        }
    }
    bool has_external_seg=false;
    int sum_ex=0;
    for(int i=0;i<process_size.size();++i){
        if(allocation[i]!=-1){
            cout<<"Process "<<i+1<<" has been allocated in "<<allocation[i]<<" block\n";
        }else{
            cout<<"Process "<<i+1<<" could not be allocated\n";
            has_external_seg=true;
        }
    }
    if(has_external_seg){
       for(int i=0;i<blocksize.size();++i){
        sum_ex+=blocksize[i];
       }         
    }
    cout<<"Sum of external fragment "<<sum_ex<<"\n";
}
int main(void){
    first_fit();
}
#include<bits/stdc++.h>
using namespace std;
void best_fit(){
    vector<int> blocksize={50, 200, 70, 115, 15}; 
    vector<int> process_size={100, 10, 35, 15, 23, 6, 25, 55, 88, 40};
    vector<int> allocation(process_size.size(),-1);

    for(int i=0;i<process_size.size();++i){
        int best_idx=-1;
        for(int j=0;j<blocksize.size();++j){
            if(blocksize[j]>=process_size[i]){
                if(best_idx==-1 || blocksize[j]<blocksize[best_idx]){
                    best_idx=j;
                }
            }
        }
        if(best_idx!=-1){
            allocation[i]=best_idx;
            blocksize[best_idx]-=process_size[i];
        }
    }

    bool has_external_fg=false;
    for(int i=0;i<process_size.size();++i){
        if(allocation[i]!=-1){
            cout<<"Process "<<i+1<<" has been allocated in "<<allocation[i]<<" block\n";
        }else{
            cout<<"Process "<<i+1<<" could not be allocated\n";
            has_external_fg=true;
        }
    }
    int sum_ext=0;
    if(has_external_fg){
        for(int i=0;i<blocksize.size();++i){
            sum_ext+=blocksize[i];
        }
    }
    cout<<"Sum of external fragment : "<<sum_ext<<"\n";
}
int main(void){
    best_fit();
}
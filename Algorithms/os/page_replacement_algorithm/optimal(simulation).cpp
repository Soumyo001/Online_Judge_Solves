#include<bits/stdc++.h>
using namespace std;
//page hit -> 1
//page fault -> 0
vector<vector<int>> frame;
vector<int> req_pages;
int frames,req_number;

bool load(int page_n,int column){

    for(int i=frames;i>=1;--i){
        frame[i][column]=frame[i][column-1];
        if(frame[i][column]==page_n && frame[0][column]==-1){
            frame[0][column]=1;
        }else if(frame[i][column]==-1 && frame[0][column]==-1){
            frame[i][column]=page_n;
            frame[0][column]=0;
        }
    }

    return (frame[0][column]==-1?false:true);
}
void optimal(int column){
    unordered_map<int,int> first_occur_last;
    int longest_dist = INT_MIN;
    int  page_frame=-1;

    for(int i=frames;i>=1;--i){
        for(int j=column;j<=req_number;++j){
            if(req_pages[j]==frame[i][column]){
                first_occur_last[frame[i][column]]=i;
                if(longest_dist<j){
                    longest_dist=j;
                    page_frame=i;
                }
                break;
            }
        }
        if(first_occur_last.find(frame[i][column])==first_occur_last.end()){
            //longest_dist=INT_MAX;
            page_frame=i;
            break;
        }
    }
    
    frame[page_frame][column]=req_pages[column];
    frame[0][column]=0;
}
void load_pages(){
    for(int i=1;i<=req_number;++i){
        if(!load(req_pages[i],i)){
            optimal(i);
        }
    }
}
int main(void){
    cin>>frames;
    cin>>req_number;

    frame.resize(frames+1);
    for(int i=0;i<=frames;++i){
        frame[i].resize(req_number+1,-1);
    }
    req_pages.resize(req_number+1,0);

    for(int i=1;i<=req_number;++i) cin>>req_pages[i];

    load_pages();

    cout<<"\n";

    for(int i=0;i<=frames;++i){
        for(int j=1;j<=req_number;++j){
            cout<<frame[i][j]<<"\t";
        }
        cout<<(i==0? "\n\n":"\n");
    }
}
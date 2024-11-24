#include<bits/stdc++.h>
using namespace std;
//page hit -> 1
//page fault -> 0
int frames,req_pages;
vector<vector<int>> frame;
vector<int> req_page;

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
    return frame[0][column]==-1 ? false : true;
}

void lru(int column){
    //unordered_map<int,int> first_occur_last;
    int smallest = INT_MAX;
    int frame_n=-1;
    for(int i=frames;i>=1;--i){
        for(int j=column;j>=1;--j){
            if(req_page[j]==frame[i][column]){
                //first_occur_last[frame[i][column]]=i;
                if(smallest>j){
                    smallest=j;
                    frame_n=i;
                }
                break;
            }
        }
        // if(first_occur_last.find(frame[i][column])!=first_occur_last.end()){
        //     frame_n=i;
        //     break;
        // } in lru, pages in frame is always available in the past request.
    }

    frame[frame_n][column]=req_page[column];
    frame[0][column]=0;
}

void load_pages(){
    for(int i=1;i<=req_pages;++i){
        if(!load(req_page[i],i)){
            lru(i);
        }
    }
}

int main(void){
    cin>>frames>>req_pages;

    frame.resize(frames+1);
    req_page.resize(req_pages+1,0);
    for(int i=0;i<=frames;++i) frame[i].resize(req_pages+1,-1);

    for(int i=1;i<=req_pages;++i) cin>>req_page[i];

    load_pages();

     cout<<"\n";

    for(int i=0;i<=frames;++i){
        for(int j=1;j<=req_pages;++j){
            cout<<frame[i][j]<<"\t";
        }
        cout<<(i==0? "\n\n":"\n");
    }
}
#include<bits/stdc++.h>
using namespace std;
struct Process{
    int process_id=0,
    arrival_time=0,
    burst_time=0,
    remaining_time=0,
    completion_time=0,
    turn_around_time=0,
    waiting_time=0,
    response_time=-1;
    bool inQ=false;
};
struct shortest_time{
    bool operator()(const Process& a,const Process& b){
        if(a.remaining_time==b.remaining_time)
            return a.arrival_time>b.arrival_time;
        
        return a.remaining_time>b.remaining_time;
    }
};
vector<Process> process;

void srtf(int process_count){
    priority_queue<Process,vector<Process>,shortest_time> q;
    int current_time = 0;
    int completed = 0;
    while(completed<process_count){
        for(int i=0;i<process_count;++i){
            if(process[i].arrival_time<=current_time && !process[i].inQ){
                process[i].inQ=true;
                q.push(process[i]);
            }
        }
        if(q.empty()){
            ++current_time;
            continue;
        }
        Process curr = q.top();q.pop();
        if(process[curr.process_id].response_time==-1){
            process[curr.process_id].response_time=current_time-process[curr.process_id].arrival_time;
        }
        ++current_time;
        --process[curr.process_id].remaining_time;
        if(process[curr.process_id].remaining_time==0){
            process[curr.process_id].completion_time=current_time;
            process[curr.process_id].turn_around_time=current_time-process[curr.process_id].arrival_time;
            process[curr.process_id].waiting_time=process[curr.process_id].turn_around_time-process[curr.process_id].burst_time;
            ++completed;
        }else{
            q.push(process[curr.process_id]);
        }
    }
}

void print(int process_count){
    for(int i=0;i<process_count;++i){
        cout<<"Process "<<process[i].process_id+1<<": "
            << "Completion Time = " << process[i].completion_time << ", "
            << "Turnaround Time = " << process[i].turn_around_time << ", "
            << "Waiting Time = " << process[i].waiting_time << ", "
            << "Response Time = " << process[i].response_time << endl;
    }
}

int main(void){
    int n;cin>>n;
    process.resize(n);
    for(int i=0;i<n;++i){
        process[i].process_id=i;
        cin>>process[i].arrival_time>>process[i].burst_time;
        process[i].remaining_time=process[i].burst_time;
    }
    srtf(n);
    print(n);
}

/*
void srtf(int process_count){
    priority_queue<Process,vector<Process>,shortest_time> q;
    int current_time=0;
    int completed = 0;
    pair<int,int> first_p = {-1,INT_MAX};

    for(int i=0;i<process_count;++i){
        if(first_p.second>process[i].arrival_time && process[i].arrival_time>=0){
            first_p.second=process[i].arrival_time;
            first_p.first=i;
        }
    }
    process[first_p.first].inQ=true;
    q.push(process[first_p.first]);

    while(!q.empty() || completed < process_count){
        Process p = q.top();q.pop();
        if(process[p.process_id].response_time==-1){
            process[p.process_id].response_time=current_time-process[p.process_id].arrival_time;
        }
        process[p.process_id].remaining_time-=1;
        current_time+=1;
        if(process[p.process_id].remaining_time==0){
            process[p.process_id].completion_time = current_time;
            process[p.process_id].turn_around_time = current_time -  process[p.process_id].arrival_time;
            process[p.process_id].waiting_time = process[p.process_id].turn_around_time - process[p.process_id].burst_time;
            ++completed;
        }else{
            q.push(process[p.process_id]);
        }
        for(int i=0;i<process_count;++i){
            if(process[i].arrival_time<=current_time && process[i].inQ==false){
                process[i].inQ=true;
                q.push(process[i]);
            }
        }

    }
}
*/
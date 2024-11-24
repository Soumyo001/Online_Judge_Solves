#include<bits/stdc++.h>
using namespace std;
//don't ask for a non pre-emptive version of this
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

vector<Process> process;

void rr(int process_number,int time){
    queue<Process> rd_q,rn_q;
    int completed=0,current_time=0;
    Process curr;
    while(completed<process_number){
        for(int i=0;i<process_number;++i){
            if(process[i].arrival_time<=current_time && process[i].remaining_time>0 && !process[i].inQ){
                process[i].inQ=true;
                rn_q.push(process[i]);
            }
        }

        while(!rd_q.empty()){
            rn_q.push(rd_q.front());rd_q.pop();
        }

        if(rn_q.empty()){
            ++current_time;
            continue;
        }


        curr = rn_q.front();rn_q.pop();
        if(process[curr.process_id].response_time==-1){
            process[curr.process_id].response_time = current_time - process[curr.process_id].arrival_time;
        }

        int exec_time = min(process[curr.process_id].remaining_time,time);
        current_time+=exec_time;
        process[curr.process_id].remaining_time-=exec_time;

        if(process[curr.process_id].remaining_time==0){
            process[curr.process_id].completion_time = current_time;
            process[curr.process_id].turn_around_time = current_time - process[curr.process_id].arrival_time;
            process[curr.process_id].waiting_time = process[curr.process_id].turn_around_time - process[curr.process_id].burst_time;
            ++completed;
        }else{
            rd_q.push(process[curr.process_id]);
        }

    }
}

void print(int process_count){
    for(int i=0;i<process_count;++i){
        cout<<"Process "<<process[i].process_id+1<<": "
            << "Completion Time = " << process[i].completion_time << ", "
            << "Turnaround Time = " << process[i].turn_around_time << ", "
            << "Waiting Time = " << process[i].waiting_time << ", "
            << "Response Time = " << process[i].response_time << "\n";
    }
}

int main(void){
    int n;cin>>n;
    int time;cin>>time;
    process.resize(n);
    for(int i=0;i<n;++i){
        process[i].process_id=i;
        cin>>process[i].arrival_time>>process[i].burst_time;
        process[i].remaining_time=process[i].burst_time;
    }

    rr(n,time);
    print(n);
}
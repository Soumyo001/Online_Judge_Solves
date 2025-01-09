#include<bits/stdc++.h>
using namespace std;

long long solve (int N, int start, int finish, vector<int> Ticket_cost) {

    --start;--finish;
    long long clock_cost=0,anti_cost=0;
    int curr=start;

    //clockwise iteration
    while(curr!=finish){
        clock_cost+=Ticket_cost[curr];
        curr=(curr+1)%N;
    }
    curr=start;

    //anti-clockwise iteration
    while(curr!=finish){
        anti_cost+=Ticket_cost[(curr-1+N)%N];
        curr=(curr-1+N)%N;
    }
    return min(clock_cost,anti_cost);
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int start;
    cin >> start;
    int finish;
    cin >> finish;
    vector<int> Ticket_cost(N);
    for(int i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    {
    	cin >> Ticket_cost[i_Ticket_cost];
    }


    long long out_;
    out_ = solve(N, start, finish, Ticket_cost);
    cout << out_;
}



 
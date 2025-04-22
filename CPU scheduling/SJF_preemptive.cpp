#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct process{
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    bool done=false;
    int remaining_time;
};

int main(){
   int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector <process> process(n);
    for (int i=0;i<n;i++){
          cout << "Enter the arrival time and burst time for process " << i+1 << ": ";
          cin >> process[i].arrival_time >> process[i].burst_time;
          process[i].id = i+1;
          process[i].remaining_time=process[i].burst_time;
    }

    int currentTime=0;
    float totalWaitingTime=0;
    float totalTurnaroundTime=0;
    int completed=0;

    while(completed <n){
        int idx=-1;
        int minRT=INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!process[i].done && process[i].arrival_time <= currentTime) {
                if (process[i].remaining_time < minRT) {
                    idx = i;
                    minRT = process[i].remaining_time;
                } else if (process[i].remaining_time == minRT) {
                    // Tie-breaker: choose process with earlier arrival time
                    if (process[i].arrival_time < process[idx].arrival_time ||
                        (process[i].arrival_time == process[idx].arrival_time && process[i].id < process[idx].id)) {
                        idx = i;
                    }
                }
            }
        }        

        if(idx!=-1){
            currentTime++;
            process[idx].remaining_time--;
            if(process[idx].remaining_time==0){
                process[idx].completion_time=currentTime;
                process[idx].turnaround_time=process[idx].completion_time-process[idx].arrival_time;
                process[idx].waiting_time=process[idx].turnaround_time-process[idx].burst_time;
                totalWaitingTime+=process[idx].waiting_time;
                totalTurnaroundTime+=process[idx].turnaround_time;
                process[idx].done=true;
                completed++;                    
            }
        }else{
            currentTime++;
        }
    }

        cout<<left<<setw(10)<<"Process ID"<<setw(15)<<"Arrival Time"<<setw(15)<<"Burst Time"<<setw(15)<<"Completion Time"<<setw(15)<<"Waiting Time"<<setw(15)<<"Turnaround Time"<<endl;
        for (auto &p:process){
            cout<<left<<setw(10)<<p.id<<setw(15)<<p.arrival_time<<setw(15)<<p.burst_time<<setw(15)<<p.completion_time<<setw(15)<<p.waiting_time<<setw(15)<<p.turnaround_time<<endl;
        }
        cout<<endl;
        cout << "Average Waiting Time: " << (float)totalWaitingTime/n << endl;  
        cout << "Average Turnaround Time: " << (float)totalTurnaroundTime/n << endl;
        cout << "Throughput: " << (float)n/currentTime << endl;
        cout << "CPU Utilization: " << (float)currentTime/(currentTime+totalWaitingTime) * 100 << "%" << endl;


    return 0;
}
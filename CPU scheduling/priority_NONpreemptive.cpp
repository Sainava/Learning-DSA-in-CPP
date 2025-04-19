#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Process{
    int id ;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    bool done=false;
    int priority;
};


int main(){
    int n;
    cout << "Enter the number of processes: ";
    cin  >> n;

    vector <Process> process(n);

    for (int i=0;i<n;i++){
        cout <<"Enter the arrival time ,and burst time and priority(lower number=higher priority) of process "<< i+1 << ": ";
        cin >> process[i].arrival_time >> process[i].burst_time>> process[i].priority;
        process[i].id=i+1;
    }

    int completed=0,currentTime=0;
    float totalWaitingTime=0,totalTurnaroundTime=0;

    while(completed < n){
        int idx=-1;
        int minPriority=INT_MAX;
        for (int i=0;i<n;i++){
            if(!process[i].done && process[i].arrival_time<=currentTime && process[i].priority<minPriority){
                minPriority=process[i].priority;
                idx=i;
            }
        }if(idx!=-1){
            currentTime=max(currentTime,process[idx].arrival_time);
            process[idx].completion_time=process[idx].burst_time+currentTime;
            process[idx].turnaround_time=process[idx].completion_time-process[idx].arrival_time;
            process[idx].waiting_time=process[idx].turnaround_time-process[idx].burst_time;
            currentTime=process[idx].completion_time;
            process[idx].done=true;
            completed++;
            totalWaitingTime+=process[idx].waiting_time;
            totalTurnaroundTime+=process[idx].turnaround_time;
        }else{
            currentTime++;
        }

    }



    cout << "\nProcess Table:\n";
    cout << left << setw(12) << "Process ID" << setw(15) << "Arrival" << setw(15)
         << "Burst" << setw(15) << "Priority" << setw(18) << "Completion"
         << setw(15) << "Waiting" << setw(15) << "Turnaround" << endl;

    for (auto &p : process) {
        cout << left << setw(12) << p.id << setw(15) << p.arrival_time
             << setw(15) << p.burst_time << setw(15) << p.priority
             << setw(18) << p.completion_time << setw(15) << p.waiting_time
             << setw(15) << p.turnaround_time << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl; 
    return 0;
}
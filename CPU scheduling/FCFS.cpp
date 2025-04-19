#include<iostream>
#include<vector>
#include<algorithm> 
#include<iomanip>
using namespace std;


struct Process{
    int id;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main(){
   int n;
   cout << "Enter the number of processes: ";
   cin >> n;
   vector <Process> processes(n);
   for (int i=0;i<n;i++){
         cout << "Enter the arrival time and burst time for process " << i+1 << ": ";
         cin >> processes[i].arrival_time >> processes[i].burst_time;
         processes[i].id = i+1;
   }

   sort(processes.begin(),processes.end(),[](Process a, Process b){
       return a.arrival_time < b.arrival_time;
   });

   int currentTime=0;
   int  totalWaitingTime=0;
   int totalTurnaroundTime=0;

   for(int i=0;i<n;i++){
        if (currentTime<processes[i].arrival_time){
            currentTime=processes[i].arrival_time;
        }
        processes[i].start_time=currentTime;
        processes[i].completion_time=processes[i].start_time+processes[i].burst_time;
        currentTime=processes[i].completion_time;

        // calulate waiting time and turnaround time
        processes[i].turnaround_time=processes[i].completion_time-processes[i].arrival_time;
        processes[i].waiting_time=processes[i].turnaround_time-processes[i].burst_time;

        // update total waiting time and turnaround time
        totalWaitingTime+=processes[i].waiting_time;
        totalTurnaroundTime+=processes[i].turnaround_time;

        
        

   }
   cout<<left<<setw(10)<<"Process ID"<<setw(15)<<"Arrival Time"<<setw(15)<<"Burst Time"<<setw(15)<<"Start Time"<<setw(15)<<"Completion Time"<<setw(15)<<"Waiting Time"<<setw(15)<<"Turnaround Time"<<endl; 


   for (auto &p:processes){
       cout<<left<<setw(10)<<p.id<<setw(15)<<p.arrival_time<<setw(15)<<p.burst_time<<setw(15)<<p.start_time<<setw(15)<<p.completion_time<<setw(15)<<p.waiting_time<<setw(15)<<p.turnaround_time<<endl;
   }
   cout<<endl;

   cout << "Average Waiting Time: " << (float)totalWaitingTime/n << endl;
   cout << "Average Turnaround Time: " << (float)totalTurnaroundTime/n << endl;



    return 0;
}
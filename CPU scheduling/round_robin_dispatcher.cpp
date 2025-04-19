#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id, arrival_time, burst_time, remaining_time, completion_time, turnaround_time, waiting_time;
};

int main() {
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time and burst time for process " << i << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].id = i;
        processes[i].remaining_time = processes[i].burst_time;
    }

    cout << "Enter the time quantum: ";
    cin >> quantum;

    queue<int> q;
    vector<bool> inQueue(n, false);
    int currentTime = 0, completed = 0;

    // Add initially arrived processes
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time == 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    

    int dispatchTime=1;
    while (completed < n) {
         // Add new processes that have arrived at currentTime
    for (int i = 0; i < n; i++) {
        if (!inQueue[i] && processes[i].arrival_time <= currentTime) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    // If the queue is empty, just increment currentTime and check again
    if (q.empty()) {
        currentTime++;
        continue;
    }

        int idx = q.front();
        q.pop();

        currentTime += dispatchTime;
        int execTime = min(quantum, processes[idx].remaining_time);

        // Process second by second to catch new arrivals
        for (int t = 0; t < execTime; t++) {
            currentTime++;

            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && processes[i].arrival_time == currentTime) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
        }

        processes[idx].remaining_time -= execTime;

        if (processes[idx].remaining_time == 0) {
            completed++;
            processes[idx].completion_time = currentTime;
            processes[idx].turnaround_time = currentTime - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            totalWaitingTime += processes[idx].waiting_time;
            totalTurnaroundTime += processes[idx].turnaround_time;
        } else {
            q.push(idx);
        }
    }

    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (const auto& p : processes) {
        cout << "P" << p.id << "\t" << p.arrival_time << "\t" << p.burst_time << "\t"
             << p.completion_time << "\t\t" << p.turnaround_time << "\t\t" << p.waiting_time << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;
    cout << "Throughput: " << (float)n / currentTime << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter arrival time, burst time, and priority (lower number = higher priority) for process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time >> processes[i].priority;
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int time = 0;
    int completed = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        // Select process with highest priority that's ready
        for (int i = 0; i < n; ++i) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    idx = i;
                } else if (processes[i].priority == highest_priority) {
                    // Tie-breaker: earlier arrival time
                    if (processes[i].arrival_time < processes[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            processes[idx].remaining_time--;

            // If the process just finished
            if (processes[idx].remaining_time == 0) {
                processes[idx].completion_time = time + 1;
                processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
                processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;

                total_turnaround_time += processes[idx].turnaround_time;
                total_waiting_time += processes[idx].waiting_time;

                completed++;
            }
        }

        time++;
    }

    // Print result table
    cout << "\nProcess Table:\n";
    cout << left << setw(12) << "Process ID" << setw(15) << "Arrival"
         << setw(15) << "Burst" << setw(15) << "Priority"
         << setw(18) << "Completion" << setw(15) << "Waiting"
         << setw(15) << "Turnaround" << endl;

    for (const auto &p : processes) {
        cout << left << setw(12) << p.id << setw(15) << p.arrival_time
             << setw(15) << p.burst_time << setw(15) << p.priority
             << setw(18) << p.completion_time << setw(15) << p.waiting_time
             << setw(15) << p.turnaround_time << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_waiting_time / n << endl;
    cout << "Average Turnaround Time: " << total_turnaround_time / n << endl;

    return 0;
}

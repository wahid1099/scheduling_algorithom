#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int at;  // Arrival Time
    int bt;  // Burst Time
    int ct;  // Completion Time
    int tat; // Turnaround Time
    int wt;  // Waiting Time
};

int main() {
    int n;

    // Input the number of processes
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // process id
        std::cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        std::cin >> processes[i].at >> processes[i].bt;
    }

    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int currentTime = 0;

    // Calculate CT, TAT, WT for each process
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].at) {
            currentTime = processes[i].at; // If CPU is idle, set current time to arrival time
        }

        processes[i].ct = currentTime + processes[i].bt; // Completion time
        currentTime = processes[i].ct;                   // Update current time

        processes[i].tat = processes[i].ct - processes[i].at; // Turnaround time
        processes[i].wt = processes[i].tat - processes[i].bt; // Waiting time
    }

    // Output the result
    std::cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& process : processes) {
        std::cout << "P" << process.id << "\t" << process.at << "\t" << process.bt << "\t"
                  << process.ct << "\t" << process.tat << "\t" << process.wt << "\n";
    }

    return 0;
}

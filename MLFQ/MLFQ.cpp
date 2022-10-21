//
// Created by Angelo Alies on 10/15/22.
//
#include <iostream>
#include "MLFQ.h"
#include<queue>
#include<vector>
#include<iomanip>
using std::cout;

//TODO: (complete) expression result is never used. Investigate issue.
int main() {
    Scheduler obj; // Constructor used to call all processes and mlfq
    return 0;
}

void Scheduler::mlfq(vector<vector<int>> processes, queue<int> readyQueueRR1,vector<int> processBurstIndex) {
    vector<int> queue_level(numProcesses, 1);
    vector<int> arrivalTime(processes.size(), 0);
    vector<int> waitingTime(processes.size(), 0);
    vector<int> tat(processes.size(), 0);
    vector<int> responseTime(processes.size(), -1);
    vector<pair<int, int>> ioreturn;
    queue<int> readyQueueRR2;
    queue<int> readyQueueFCFS3;
    vector<int> complete(processes.size(), 0);

    for (int i = 0; i < processes.size(); i++) {
        ioreturn.emplace_back(INT_MAX, i);
    }

    while (!readyQueueRR1.empty() || !readyQueueRR2.empty() ||
           !readyQueueFCFS3.empty()) {
        // cpu burst
        if (!readyQueueRR1.empty()) {
            // tq = 5
            int process_index = readyQueueRR1.front();
            readyQueueRR1.pop();

            waitingTime[process_index] += time - arrivalTime[process_index];
            if (responseTime[process_index] == -1) {
                responseTime[process_index] = time - arrivalTime[process_index];
            }
            int localBurstTime =
                    processes[process_index]
                    [processBurstIndex[process_index]]; // process getting cpu
            // burst time
            printContextSwitchData(processes, process_index, readyQueueRR1,processBurstIndex, time);
            if (localBurstTime > TQ_RR1) { // tq expired
                time += TQ_RR1;
                processes[process_index][processBurstIndex[process_index]] =
                        localBurstTime - TQ_RR1;
                readyQueueRR2.push(process_index);
                queue_level[process_index] = 2;
                arrivalTime[process_index] = time;
            } else {
                time += localBurstTime;
                if (processBurstIndex[process_index] <=
                    processes[process_index].size() - 3) {
                    for (int i = 0; i < processes.size(); i++) {
                        if (ioreturn[i].second == process_index) {
                            ioreturn[i].first = processes[process_index][processBurstIndex[process_index] + 1] +
                                               time;
                            break;
                        }
                    }
                } else {
                    complete[process_index] = 1;
                }
                processBurstIndex[process_index] += 2;
            }
        } else if (!readyQueueRR2.empty()) {
            // tq = 10
            int process_index = readyQueueRR2.front();
            readyQueueRR2.pop();

            waitingTime[process_index] += time - arrivalTime[process_index];
            int localBurstTime =
                    processes[process_index]
                    [processBurstIndex[process_index]]; // process getting cpu
            // burst time
            printContextSwitchData(processes, process_index, readyQueueRR2,processBurstIndex, time);
            if (localBurstTime > TQ_RR2) { // tq expired
                time += TQ_RR2;
                processes[process_index][processBurstIndex[process_index]] =
                        localBurstTime - TQ_RR2;
                readyQueueFCFS3.push(process_index);
                queue_level[process_index] = 3;
                arrivalTime[process_index] = time;
            } else {
                time += localBurstTime;
                if (processBurstIndex[process_index] <=
                    processes[process_index].size() - 3) {
                    for (int i = 0; i < processes.size(); i++) {
                        if (ioreturn[i].second == process_index) {
                            ioreturn[i].first =
                                    processes[process_index]
                                    [processBurstIndex[process_index] + 1] +
                                    time;
                            break;
                        }
                    }
                } else {
                    complete[process_index] = 1;
                }
                processBurstIndex[process_index] += 2;
            }
        } else if (!readyQueueFCFS3.empty()) {
            int process_index = readyQueueFCFS3.front();
            readyQueueFCFS3.pop();

            // waiting time in ready queue
            waitingTime[process_index] += time - arrivalTime[process_index];
            printContextSwitchData(processes, process_index, readyQueueFCFS3,
                                   processBurstIndex, time);
            time += processes[process_index]
            [processBurstIndex[process_index]]; // process getting cpu
            // burst time

            if (processBurstIndex[process_index] <=
                processes[process_index].size() - 3) {
                for (int i = 0; i < processes.size(); i++) {
                    if (ioreturn[i].second == process_index) {
                        ioreturn[i].first =
                                processes[process_index][processBurstIndex[process_index] + 1] +
                                time;
                        break;
                    }
                }
            } else {
                complete[process_index] = 1;
            }
            processBurstIndex[process_index] += 2;
        }
        sort(ioreturn.begin(), ioreturn.end());

        if (readyQueueRR1.empty() && readyQueueRR2.empty() &&
            readyQueueFCFS3.empty()) {

            while (ioreturn[0].first != INT_MAX && ioreturn[0].first > time) {
                time++;
                idle_Cpu_Time++;
            }
        }

        for (int i = 0; i < processes.size(); i++) {
            if (ioreturn[i].first <= time) {
                if (queue_level[ioreturn[i].second] == 1)
                    readyQueueRR1.push(ioreturn[i].second);
                else if (queue_level[ioreturn[i].second] == 2)
                    readyQueueRR2.push(ioreturn[i].second);
                else
                    readyQueueFCFS3.push(ioreturn[i].second);
                arrivalTime[ioreturn[i].second] = ioreturn[i].first;
                ioreturn[i].first = INT_MAX;
            }
        }
    }

    int burst_time = time - idle_Cpu_Time;

    for (unsigned int i = 0; i < processes.size(); ++i) {
        int total_burst_time = 0;
        for (int j : processes[i]) {
            total_burst_time += j;
        }
        tat[i] += total_burst_time + waitingTime[i];
    }

    cout << "Multi Level Feedback Queue" << "\n";
    cout << "Total time of "<< numProcesses << " processes: " << time << "\n";
    cout << "CPU Utilization: " << (float)burst_time / time * 100 << "\n";
    cout << "__________________________________________________ " << "\n";

    int twt = 0, ttat = 0, trt = 0;

    for(unsigned int i = 0; i < processes.size(); ++i)
    {
        cout << "P" << i + 1;
        cout << " Tw: " << waitingTime[i] << "   Ttr: " << tat[i] << "   Tr: " << responseTime[i] << "\n";
        twt += waitingTime[i];
        ttat += tat[i];
        trt += responseTime[i];
    }

    cout << "__________________________________________________ " << "\n";
    cout << "Avg Tw: " << (float)twt / processes.size();
    cout << " | Avg Ttr: " << (float)ttat / processes.size();
    cout << " | Avg Tr: " << (float)trt / processes.size();

}

// function to print the queue
void Scheduler::printQueue(queue<int> q, vector<vector<int>> processes,
                           vector<int> processBurstIndex) {
    // printing content of queue
    cout << setfill(' ') << setw(10) << "Process" << setw(10) << "Burst" << endl;
    if (!q.empty()) {
        while (!q.empty()) {
            int pid = q.front();
            cout << setfill(' ') << setw(10) << "P" << pid << setw(10)
                 << processes[pid][processBurstIndex[pid]] << endl;
            q.pop();
        }
    } else {
        cout << setfill(' ') << setw(10) << "[empty]" << setw(10) << "N/A" << endl;
    }
    cout << endl;
}


void Scheduler::printContextSwitchData(vector<vector<int>> processes, int process_index,queue<int> readyQueue,vector<int> processBurstIndex, int time)
{
    cout << setfill('-') << setw(40) << "-" << endl;
    cout << "Current Execution Time: " << time << endl << endl;
    cout << "Next Process on the CPU: P" << process_index << endl;
    cout << setfill('-') << setw(40) << "-" << endl << endl;
    cout << "Ready queue:" << endl;
    printQueue(std::move(readyQueue), std::move(processes), std::move(processBurstIndex));
    cout << setfill('-') << setw(40) << "-" << endl;
}

//
// Created by angel on 10/19/2022.
//

#ifndef MLFQ_MLFQ_H
#define MLFQ_MLFQ_H
#include <bits/stdc++.h>
using namespace std;

class Scheduler{
public:
    void mlfq(vector<vector<int>> processes, queue<int> readyQueueRR1,vector<int> processBurstIndex);
    void printCompleteProcesses(vector<int> complete);
    void printQueue(queue<int> q, vector<vector<int>> processes,vector<int> processBurstIndex);
    void printContextSwitchData(vector<vector<int>> processes, int process_index,queue<int> readyQueue,vector<int> processBurstIndex, int time);

private:
    double time = 0;
    double idle_Cpu_Time = 0;
    int tqrq1 = 5, tqrq2 = 10;
};
#endif //MLFQ_MLFQ_H

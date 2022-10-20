//
// Created by Angelo Alies on 10/15/2022.
//

#ifndef MLFQ_MLFQ_H
#define MLFQ_MLFQ_H
#include<vector>
#include<queue>
using namespace std;



class Scheduler{
public:

    const int numProcesses = 8;

    Scheduler(){
        vector<vector<int>> processes(numProcesses);
        queue<int> readyQueueRR1;
        vector<int> processBurstIndex(numProcesses, 0);
        processes[0] = {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4};
        processes[1] = {4, 48, 5, 44, 7, 42, 12, 37, 9, 76, 4, 41, 9, 31, 7, 43, 8};
        processes[2] = {8, 33, 12, 41, 18, 65, 14, 21, 4, 61, 15, 18, 14, 26, 5, 31, 6};
        processes[3] = {3, 35, 4, 41, 5, 45, 3, 51, 4, 61, 5, 54, 6, 82, 5, 77, 3};
        processes[4] = {16, 24, 17, 21, 5, 36, 16, 26, 7, 31, 13, 28, 11, 21, 6, 13, 3, 11, 4};
        processes[5] = {11, 22, 4, 8, 5, 10, 6, 12, 7, 14, 9, 18, 12, 24, 15, 30, 8};
        processes[6] = {14, 46, 17, 41, 11, 42, 15, 21, 4, 32, 7, 19, 16, 33, 10};
        processes[7] = {4, 14, 5, 33, 6, 51, 14, 73, 16, 87, 6};

        for (int i = 0; i < processes.size(); i++) readyQueueRR1.push(i);

        cout << endl << "----MLFQ----" << endl;
        mlfq(processes, readyQueueRR1, processBurstIndex);
    }

    void mlfq(vector<vector<int>>, queue<int>,vector<int>);
    void printCompleteProcesses(vector<int>);
    void printQueue(queue<int> q, vector<vector<int>>,vector<int>);
    void printContextSwitchData(vector<vector<int>>, int,queue<int>,vector<int>,int);

private:
    double time = 0;
    double idle_Cpu_Time = 0;
    int tqrq1 = 5, tqrq2 = 10;
};
#endif //MLFQ_MLFQ_H

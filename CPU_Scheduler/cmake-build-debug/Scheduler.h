//
// Created by angel on 9/24/2022.
//

#ifndef UNTITLED3_SCHEDULER_H
#define UNTITLED3_SCHEDULER_H

#include <iostream>
#include <deque>
#include <algorithm>

struct Process{
   std::deque<int> schedule;
    unsigned int counter = 0; //tracking schedule's position
    unsigned int pid_num;
    unsigned int Tw = 0; // waiting time
    unsigned int Ttr = 0; //turnaround time
    int Tr = -1; // ready time
    bool is_IO = false; // determines if i/o or cpu
    std::string pid; //name of processors
};

class Scheduler{
public:
    Scheduler(){
        
        time = 0; //total running time
        running_time = 0;
        cpuu = 0; //cpu utilization
        Process temp;

        //process 1
        temp.schedule = {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4};
        temp.pid = "P1";
        temp.pid_num = 1;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 2
        temp.schedule = {4, 48, 5, 44, 7, 42, 12, 37, 9, 76, 4, 41, 9, 31, 7, 43, 8};
        temp.pid = "P2";
        temp.pid_num = 2;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 3
        temp.schedule = {8, 33, 12, 41, 18, 65, 14, 21, 4, 61, 15, 18, 14, 26, 5, 31, 6};
        temp.pid = "P3";
        temp.pid_num = 3;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 4
        temp.schedule = {3, 35, 4, 41, 5, 45, 3, 51, 4, 61, 5, 54, 6, 82, 5, 77, 3};
        temp.pid = "P4";
        temp.pid_num = 4;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 5
        temp.schedule = {16, 24, 17, 21, 5, 36, 16, 26, 7, 31, 13, 28, 11, 21, 6, 13, 3, 11, 4};
        temp.pid = "P5";
        temp.pid_num = 5;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 6
        temp.schedule = {11, 22, 4, 8, 5, 10, 6, 12, 7, 14, 9, 18, 12, 24, 15, 30, 8};
        temp.pid = "P6";
        temp.pid_num = 6;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 7
        temp.schedule = {14, 46, 17, 41, 11, 42, 15, 21, 4, 32, 7, 19, 16, 33, 10};
        temp.pid = "P7";
        temp.pid_num = 7;
        readyQueue.push_back(temp);
        temp.schedule.clear();

        //process 8
        temp.schedule = {4, 14, 5, 33, 6, 51, 14, 73, 16, 87, 6};
        temp.pid = "P8";
        temp.pid_num = 8;
        readyQueue.push_back(temp);
        temp.schedule.clear();
    }
    //void print_FCFS(Process x);
    void FCFS();
    void SJF();
    void MLQFQ();
private:
    double time; //total running time
    double running_time;
    double cpuu; //cpu utilization
    const int processes = 8;

    std::deque<Process> readyQueue; //ready queue
    std::deque<Process> in_io; //for IO state
    std::deque<Process>::iterator it; //for in_IO removal
    std::deque<Process> complete; //completed processes


};
bool cmpCounter(Process x, Process y);
bool cmpProcess(Process x, Process y);

#endif //UNTITLED3_SCHEDULER_H

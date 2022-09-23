#include"scheduler.h"
#include<iostream>
#include<string>
#include<vector>
#include<list>


int main() {
    Scheduler obj;
    obj.FCFS();
    return 0;
}


void::Scheduler::FCFS()
{
    process obj;
    for(int i  = 0; i < pids.size(); i++)
        obj.waiting_time = obj.CPU_bursts[i-1] + obj.waiting_time;

    std::cout << "Waiting for " << obj.waiting_time;
}
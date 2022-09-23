//
// Created by Angelo Alies on 9/22/22.
//
#include<vector>
#include<string>
#include<list>
#include<fstream>
#include<sstream>

#ifndef UNTITLED_SCHEDULER_H
#define UNTITLED_SCHEDULER_H

struct process{
    process(){};
    process(std::string pid, std::vector<int> CPU_burst, std::vector<int> io_burst){
        this->name = pid;
        this->CPU_bursts = CPU_burst;
        this->IO_bursts = io_burst;
    }
    std::string name;
    std::string state; //allowed values are new,ready, waiting, terminated
    std::vector<int> CPU_bursts,IO_bursts;

    int arrival_time = 0,waiting_time = 0 ,turnaround_time = 0,response_time = 0,priority = 0;

};

class Scheduler {
private:
    std::list<process> pids; //p1..P8
    int global_clck;

public:
    Scheduler()
    {
        global_clck = 0;
        std::fstream fin("/Users/angeloalies/CLionProjects/untitled/processes.txt");
        std::string line;
        std::stringstream line_stream;
        process temp;
        while (std::getline(fin,line,' ')) {
            temp = process();
            temp.name = line;
            std::getline(fin,line); //array holds cpu,
            line = line.substr(1,line.length()-2); //holds cpu,io .... cpu_bursts

            int counter = 0;
            line_stream = std::stringstream(line);

            while(std::getline(line_stream,line,',')){
                if(counter++ % 2){
                    temp.IO_bursts.push_back(stoi(line));
                }
                else
                    temp.CPU_bursts.push_back(stoi(line));
            }
            pids.push_back(temp);
        }
        fin.close();
    }

    void FCFS();
    void SJF();
    void MLFQ();
};

#endif //UNTITLED_SCHEDULER_H

//
// Created by Angelo Alies on 9/15/22.
//
#include<iostream>
#include<vector>
#include <iomanip> //formatting purposes
//implementation of the FCFS scheduling using c++

class FCFS{
    //process
    std::vector<int> wait_t,tat,burst_time;
    //std::vector<std::vector<int>> burst_time;
    //int n; //n is the size, but we use vectors ignore otherwise
public:
    FCFS(){
        wait_t = {0};
        burst_time = {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4}; //representing our burst_time.
        tat = {0};
    }
    //turnaround time
    void turnaround_time(std::vector<int>);
    void wait_time(std::vector<int>);
    void avg_time(std::vector<int>);

};

int main(){
    FCFS obj;
    //only using 1 processes for now
    std::vector<int> process = {1,2,3,4,5,6,7,8};
//    std::vector<int> p1 = {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4};
//    std::vector<int> p2 = {4, 48, 5, 44, 7, 42, 12, 37, 9, 76, 4, 41, 9, 31, 7, 43, 8};
//    std::vector<int> p3 = {8, 33, 12, 41, 18, 65, 14, 21, 4, 61, 15, 18, 14, 26, 5, 31, 6};
//    std::vector<int> p4 = {3, 35, 4, 41, 5, 45, 3, 51, 4, 61, 5, 54, 6, 82, 5, 77, 3};
//    std::vector<int> p5 = {16, 24, 17, 21, 5, 36, 16, 26, 7, 31, 13, 28, 11, 21, 6, 13, 3, 11, 4};
//    std::vector<int> p6 = {11, 22, 4, 8, 5, 10, 6, 12, 7, 14, 9, 18, 12, 24, 15, 30, 8};
//    std::vector<int> p7 = {14, 46, 17, 41, 11, 42, 15, 21, 4, 32, 7, 19, 16, 33, 10};
//    std::vector<int> p8 = {4, 14, 5, 33, 6, 51, 14, 73, 16, 87, 6};

    std::cout << "FCFS Average Time";
    obj.avg_time(process);
}

//wait_time
void FCFS::wait_time(std::vector<int> p)
{
    //loop through all the threads waiting for the processes
    for(int i = 1; i < p.size(); i++)
        wait_t[i] = burst_time[i-1] + wait_t[i-1];
}

void FCFS::turnaround_time(std::vector<int> p)
{
    //total amount time calculation by adding
    for(auto i : p)
        tat[i] = burst_time[i] + wait_t[i];
}

void FCFS::avg_time(std::vector<int> p)
{
    int total_wt = 0, total_tat = 0;

    //call wait_time function
    wait_time(p);
    turnaround_time(p);
    printf("\nProcesses    Burst   Waiting Time   Turn around \n");

    for(auto i : p)
    {
        total_wt += wait_t[i];
        total_tat += tat[i];

      std::cout << std::setw(3) << i;
      std::cout << std::setw(13) << burst_time[i];
      std::cout << std::setw(10) << wait_t[i];
      std::cout << std::setw(15) << tat[i] << "\n";

    }

    //calculate the average
    total_wt / p.size();
    std::cout << "Average Time = " << (double)total_wt / p.size() << "\n";
    std::cout << "Average Turnaround_time = " << (double)total_tat / p.size() << "\n";
}

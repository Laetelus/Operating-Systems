//
// Created by Angelo Alies on 9/15/22.
//
#include<iostream>
#include<vector>
#include <iomanip> //formatting purposes
//implementation of the FCFS scheduling using c++

class FCFS{
    //process
    std::vector<int> wait_t,burst_time,tat;
    //int n; //n is the size, but we use vectors ignore otherwise
public:
    FCFS(){
        wait_t = {0};
        burst_time = {4,5,31,6}; //representing our burst_time.
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
    std::vector<int> p = {5, 27, 3, 31, 5, 43, 4, 18, 6, 22, 4, 26, 3, 24, 4};
    obj.avg_time(p);
}

//wait_time
void FCFS::wait_time(std::vector<int> p){
    //loop through all the threads waiting for the processes
    for(int i = 1; i < p.size(); i++)
        wait_t[i] = burst_time[i-1] + wait_t[i-1];
}

void FCFS::turnaround_time(std::vector<int> p){
    //total amount time calculation
    for(auto i : p)
        tat[i] = burst_time[i-1] + wait_t[i-1];
}

void FCFS::avg_time(std::vector<int> p){
    int total_wt = 0, total_tat = 0;
    //call wait_time function
    wait_time(p);
    turnaround_time(p);
    printf("Processes  Burst   Waiting Turn around \n");
    for(auto i : p){
        total_wt += wait_t[i];
        total_tat += tat[i];
        printf(" %d\t   %d\t\t %d \t%d\n", i+1, burst_time[i], wait_t[i], tat[i]);
        //std::cout << std::setw(5) << "\n" << burst_time[i];
//        std::cout << std::setw(2) << wait_t[i] << "\n";
//        std::cout << std::setw(2) << tat[i] << "\n";
    }
    //calculate the average
    total_wt / p.size();
    std::cout << "Average Time = " << total_wt / p.size() << std::endl;
    std::cout << "Average Turnaround_time = " << total_tat / p.size() << std::endl;
}

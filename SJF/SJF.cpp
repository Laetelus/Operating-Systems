//
// Created by Angelo Alies on 10/7/22.
//

#include "SJF.h"
#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>
using std::cout;


int main(){
    Scheduler obj;
    obj.print_SJF();
}

void Scheduler::SJF(std::deque<Process>&x){
    if(x.size() > 1)
    {
        int minBurst = 0; //index for min burst
        std::deque<Process>::iterator it;

        for(unsigned int i = 1; i < x.size(); i++)
        {
            if(x[minBurst].schedule[x[minBurst].counter] > x[i].schedule[x[i].counter])
            {
                minBurst = i;
            }
        }

        if(minBurst == 0)
        {
            //do nothing
        }
        else
        {
            it = (x.begin() + minBurst);
            //x.insert(x.begin(),x[minBurst]); //inserting element in front?
            x.push_front(x[minBurst]);
            x.erase(it);

        }
    }
}

void Scheduler::print_SJF(){

    ///////////////////////////////////////////////////////////////////////////////////////
    //TODO:
    //output all necessary values
    cpuu = running_time/(time) * 100; double avgTw = 0, avgTtr = 0, avgTr = 0;
    sort(complete.begin(), complete.end(),cmpProcess);

    //get Tr average
    for(unsigned int i = 0; i < complete.size(); i++)
    {
        avgTw = avgTw + complete[i].Tw;
        avgTr = avgTr + complete[i].Tr;
        avgTtr = avgTtr + complete[i].Ttr;
    }
    avgTw = avgTw/processes;
    avgTr = avgTr/processes;
    avgTtr = avgTtr/processes;

    cout << "Short Jobs First\nCPU Utilization: " << cpuu << "%\n";
    for(unsigned int i = 0; i < complete.size(); i++)
    {
        cout << complete[i].pid << " Tw: " << complete[i].Tw << " Ttr: " << complete[i].Ttr << " Tr: " << complete[i].Tr << '\n';
    }
    cout << "Avg. Tw: " << avgTw << " | Avg. Ttr: " << avgTtr << " | Avg. Tr: " << avgTr;
}

bool cmpProcess(const Process& x, const Process& y)
{
    return x.pid_num < y.pid_num;
}
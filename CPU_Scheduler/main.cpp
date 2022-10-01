#include "Scheduler.h"
#include <iostream>
#include <algorithm>
using std::cout;

int main() {
    Scheduler obj;
    obj.FCFS();
    return 0;
}

void Scheduler::FCFS()
{
    cpuu = running_time/(time) * 100; double avgTw = 0, avgTtr = 0, avgTr = 0;
    sort(complete.begin(), complete.end(),cmpProcess);

    //get Tr average
    for(auto & i : complete)
    {
        avgTw += i.Tw;
        avgTr += i.Tr;
        avgTtr += i.Ttr;
    }
    avgTw /= processes;
    avgTr /= processes;
    avgTtr /= processes;

    cout << "First Come First Serve\nCPU Utilization: " << cpuu << "%\n";
    for(auto & i : complete)
    {
        cout << i.pid << " Tw: " << i.Tw << " Ttr: " << i.Ttr << " Tr: " << i.Tr << "\n";
    }
    cout << "Avg. Tw: " << avgTw << " | Avg. Ttr: " << avgTtr << " | Avg. Tr: " << avgTr;
}

bool cmpProcess(const Process& x, const Process& y)
{
    return x.pid_num < y.pid_num;
}
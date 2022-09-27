#include "cmake-build-debug/Scheduler.h"
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

    //loop while readyQueue or in_IO have elements
    while(!readyQueue.empty() || !in_io.empty()) {
        if (readyQueue.front().counter == 0 && readyQueue.front().Tr == -1)
            readyQueue.front().Tr = time;

        //Time increments first, other functionalities react to it
        time++;
        cout << "CURRENT time:  " << time << "\n";

        //TODO:
        //Decrement CPUburst of currently running process at object's current counter
        //Operate only on front of readyQueue
        //If front of readyQueue's currently selected schedule is 0, swap IO state
        if (!readyQueue.empty()) {
            //decay current CPU burst
            //increase Tw of everything else in queue
            //for loop only runs as long as
            //there is more than one element in readyQueue

            //once it reaches each process iterates through the elements.
            cout << "Now Running:  " << readyQueue.front().pid << "\n";
            readyQueue.front().schedule[readyQueue.front().counter]--;
            running_time++;

            //iterates through each process p1...p8
            for (unsigned int i = 1; i < readyQueue.size(); i++) {
                readyQueue[i].Tw++;
            }

            //
        }

        if (readyQueue.empty()) {
            cout << "CPU idle" << "\n";
        }


        if (!in_io.empty()) {
            //decrement IO bursts of all Processes in in_io
            for (size_t i = 0; i < in_io.size(); i++) {
                in_io[i].schedule[in_io[i].counter]--;

                //if currently observed IO burst is equal to zero
                //aka: If IO burst is complete, iterate schedule counter
                //inverse IO state
                //push to readyQueue
                if (in_io[i].schedule[in_io[i].counter] == 0) {
                    in_io[i].counter++; //move to next schedule burst for currently selected Process
                    in_io[i].is_IO = !in_io[i].is_IO; //flip IO state bool for current Process
                    it = in_io.begin() + i; //create vector::iterator pointing at current Process
                    readyQueue.push_back(in_io[i]); //move selected Process back to readyQueue
                    in_io.erase(
                            it); //erase selected Process from in_io (moves everything to the left, so need to decrement i)
                    i--; //decrement i to adjust to new vector size
                }
            }

            if (in_io.size() > 1) {
                 //nothing
            }
                //cannot use push_back when there is only 1 element in vector
                //use in_io clear instead
                //if in_io size is 1 and the Process' IO burst is 0
            else if (in_io.size() == 1 && in_io.front().schedule[in_io.front().counter] == 0) {
                in_io.front().counter++;
                in_io.front().is_IO = !in_io.front().is_IO;
                readyQueue.push_back(in_io.front());
                in_io.clear();
            }

        }


        //secondary check for after CPU bursts and IO bursts are decremented
        //only runs checks if there is something in readyQueue
        if (!readyQueue.empty()) {
            //if CPU burst at front of queue is 0 (is finished)
            //and if it is not the last CPU burst of the schedule,
            //send to IO vector
            if ((readyQueue.front().schedule[readyQueue.front().counter] == 0)
                && (readyQueue.front().counter != (readyQueue.front().schedule.size() - 1))) {
                readyQueue.front().counter++; //increment to next burst
                readyQueue.front().is_IO = !readyQueue.front().is_IO; //swap IO burst

                in_io.push_back(readyQueue.front()); //send to IO vector
                sort(in_io.begin(), in_io.end(), cmpProcess);
                cout << readyQueue.front().pid << " CPU burst finished - sent to IO\n";
                readyQueue.erase(readyQueue.begin()); //pop front of readyQueue

            }
                //else if the last CPU burst in element is now 0, end process entirely
            else if (readyQueue.front().schedule[readyQueue.front().schedule.size() - 1] == 0) {
                readyQueue.front().Ttr = time;
                complete.push_back(readyQueue.front()); //push to 'complete'
                cout << readyQueue.front().pid << " complete\n";
                readyQueue.erase(readyQueue.begin()); //pop front of readyQueue
            }
        }

        //output
        cout << "Ready Queue:    Process       Burst time" << "\n";
        for (auto & i : readyQueue) {
            cout << "                            " << i.pid << "              "
                 << i.schedule[i.counter] << "\n";
        }

        cout << "List of Process I/O:  " << '\n';
        cout << "Process       I/O TImes" << '\n';
        for(auto & i : in_io) {
            cout << "    " << i.pid << "            " << i.schedule[i.counter] << "\n";
        }
        cout << "\n\n";
    }

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
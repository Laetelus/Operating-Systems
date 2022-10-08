//
// Created by Angelo Alies on 10/7/22.
//

#ifndef SJF_SJF_H
#define SJF_SJF_H

#include <iostream>
#include<deque>
#include<vector>
#include <algorithm>
using std::cout;

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

//Processor Comparison
bool cmpProcess(const Process& x, const Process& y);

class Scheduler{
public:
    Scheduler() {

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

        //Begin Scheduler Calculations

        if (readyQueue.empty()){ //memory never gets allocated
            cout << "testing";
            SJF(readyQueue); // acquiring bugs when enabled
        }


        //loop while readyQueue or in_IO have elements
        while(!readyQueue.empty() || !in_io.empty())
        {
            if(readyQueue.front().counter == 0 && readyQueue.front().Tr == -1)
            {
                readyQueue.front().Tr = time;
            }

            //Time increments first, other functionalities react to it
            time++;
            cout << "Current time:  " << time << '\n';


            ///////////////////////////////////////////////////////////////////////////////////////
            //TODO:
            //Decrement CPUburst of currently running process at object's current counter
            //Operate only on front of readyQueue
            //If front of readyQueue's currently selected schedule is 0, swap IO state
            if(readyQueue.size() > 0)
            {
                //decay current CPU burst
                //increase Tw of everything else in queue
                //for loop only runs as long as
                //there is more than one element in readyQueue
                cout << "Now Running(Next Process on CPU):  " << readyQueue.front().pid << '\n';
                readyQueue.front().schedule[readyQueue.front().counter]--;
                running_time++;

                for(unsigned int i=1; i<readyQueue.size(); i++)
                {
                    readyQueue[i].Tw++;
                }

                //
            }

            if(readyQueue.size() == 0)
            {
                cout << "CPU idle" << '\n';
            }


            /////////////////////////////////////////////////////////////////////////////////////
            //TODO:
            //Decrement IOburst of all processes pushed to IO
            //If any IOburst reaches 0, it is popped from the vector
            if(in_io.size() > 0)
            {
                //decrement IO bursts of all Processes in in_io
                for(unsigned int i=0; i<in_io.size(); i++)
                {
                    in_io[i].schedule[in_io[i].counter]--;

                    //if currently observed IO burst is equal to zero
                    //aka: If IO burst is complete, iterate schedule counter
                    //inverse IO state
                    //push to readyQueue
                    if(in_io[i].schedule[in_io[i].counter] == 0)
                    {
                        in_io[i].counter++; //move to next schedule burst for currently selected Process
                        in_io[i].is_IO = !in_io[i].is_IO; //flip IO state bool for current Process
                        it = in_io.begin() + i; //create vector::iterator pointing at current Process
                        readyQueue.push_back(in_io[i]); //move selected Process back to readyQueue
                        in_io.erase(it); //erase selected Process from in_io (moves everything to the left, so need to decrement i)
                        i--; //decrement i to adjust to new vector size
                    }
                }


                if(in_io.size() > 1)
                {
                    //nothing
                }
                    //cannot use push_back when there is only 1 element in vector
                    //use in_io clear instead
                    //if in_io size is 1 and the Process' IO burst is 0
                else if(in_io.size() == 1 && in_io.front().schedule[in_io.front().counter] == 0){
                    in_io.front().counter++;
                    in_io.front().is_IO = !in_io.front().is_IO;
                    readyQueue.push_back(in_io.front());
                    in_io.clear();
                }

            }



            ///////////////////////////////////////////////////////////////////////////////////////////////////
            //secondary check for after CPU bursts and IO bursts are decremented
            //only runs checks if there is something in readyQueue
            if (readyQueue.size() > 0)
            {
                //if CPU burst at front of queue is 0 (is finished)
                //and if it is not the last CPU burst of the schedule,
                //send to IO vector
                if((readyQueue.front().schedule[readyQueue.front().counter] == 0)
                   && (readyQueue.front().counter != (readyQueue.front().schedule.size() - 1)))
                {
                    readyQueue.front().counter++; //increment to next burst
                    readyQueue.front().is_IO = !readyQueue.front().is_IO; //swap IO burst

                    in_io.push_back(readyQueue.front()); //send to IO vector
                    cout << readyQueue.front().pid << " CPU burst finished - sent to IO\n";
                    readyQueue.erase(readyQueue.begin()); //pop front of readyQueue

                    sort(in_io.begin(), in_io.end(), cmpProcess);
                    SJF(readyQueue);
                }
                    //else if the last CPU burst in element is now 0, end process entirely
                else if(readyQueue.front().schedule[readyQueue.front().schedule.size()-1] == 0)
                {
                    readyQueue.front().Ttr = time;
                    complete.push_back(readyQueue.front()); //push to 'complete'
                    cout << readyQueue.front().pid << " complete\n";
                    readyQueue.pop_front(); //pop front of readyQueue
                    SJF(readyQueue);
                }
            }


            //output
            cout << "Ready Queue: Process     Burst"<<'\n';;
            for(auto & i : readyQueue)
            {

                cout << "                    "<< i.pid <<"     " << i.schedule[i.counter] << '\n';
            }
            cout << "List of Process I/O:  "<<'\n';
            cout<<"Process     I/O Times"<<'\n';
            for(auto & i : in_io)
            {
                cout <<"         " <<i.pid << "       " << i.schedule[i.counter] <<'\n';
            }
            cout << "}" << '\n';

            cout << "Waiting time: { ";
            for(auto & i : readyQueue)
            {
                cout << i.pid << ":" << i.Tw << " ";
            }
            cout << "}" << '\n';

            cout << "\n\n";

        }
    }

    void SJF(std::deque<Process>&x);
    void print_SJF();

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

#endif //SJF_SJF_H

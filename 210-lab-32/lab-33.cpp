#include <iostream>
#include <iomanip>
#include <deque>
#include <random>
#include <chrono>
#include "Car.h"
using namespace std;

const int SIZE = 4;
const int WIDTH = 4;
const int c15 = 15;
const int c39 = 39;
const int c46 = 46;

int rand_num();

int main() {
    deque<Car> tollLanes[SIZE];    // array of deques initlized
    
    for (int i = 0; i < SIZE; i++) {    // each lane populated with 3 cars
        for (int j = 0; j < 3; j++) {
            Car newCar;
            tollLanes[i].push_back(newCar);
        }
    }
    
    
    cout << "Intial queue:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Lane: " << i+1 << endl;
        for (auto j = 0; j < tollLanes[i].size(); j++) {
            cout << setw(WIDTH) << "[" << tollLanes[i].at(j).getYear() << " " << tollLanes[i].at(j).getMake();
            cout << " (" <<  tollLanes[i].at(j).getTransponder() << ")]"<< endl;
        }
    }
    cout << "---------\n";
    

    static int count = 0;
    while (count < 20) {
        cout << "Time: " << count + 1 << endl;
        
        for (int i = 0; i < SIZE; i++)
        {
            cout << "| Lane " << i+1 << " | ";
            int oper = rand() % 100 + 1;
            
            if (tollLanes[i].empty() == false)
            {
                if (oper <= c15)
                {   // car shifts lanes
                    int shifLane = rand_num();
                    
                    tollLanes[shifLane].push_back(tollLanes[i].at(tollLanes[i].size() - 1));
                    
                    cout << "Shifted: [" << tollLanes[i].at(tollLanes[i].size() - 1).getYear() << " ";
                    cout << tollLanes[i].at(tollLanes[i].size() - 1).getMake();
                    cout<< " (" <<  tollLanes[i].at(tollLanes[i].size() - 1).getTransponder() << ")]"<< endl;
                    
                    tollLanes[i].pop_back();
                }
                //-------------------------------------------------------------------------------------------------
                else if (oper > c15 && oper <= c39)
                { // car added to lane
                    Car newCar;
                    tollLanes[i].push_back(newCar);
                    cout << "Joined: [" << newCar.getYear() << " " << newCar.getMake();
                    cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
                }
                //-------------------------------------------------------------------------------------------------
                else if (oper >= c46 && !(tollLanes[i].empty()))
                {   // car leaves
                    cout << "Paid: [" << tollLanes[i].at(0).getYear() << " " << tollLanes[i].at(0).getMake();
                    cout<< " (" << tollLanes[i].at(0).getTransponder() << ")]"<< endl;
                    tollLanes[i].pop_front();
                }
            }
            
            else if (tollLanes[i].empty() == true && oper > 50)
            {
                Car newCar;
                tollLanes[i].push_back(newCar);
                cout << "Joined: [" << newCar.getYear() << " " << newCar.getMake();
                cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
            }
        
            //-------------------------------------------------------------------------------------------------
            else
                cout << "No change" << endl;
        }
            
        cout << endl;
        
        if (count < 20)
        {
            cout << "Updated Queue:" << endl;
            
            for (int i = 0; i < SIZE; i++) {
                cout << "Lane: " << i+1 << endl;
                
                if (!(tollLanes[i].empty())) {
                    for (auto j = 0; j < tollLanes[i].size(); j++) {
                        cout << setw(WIDTH) << "[" << tollLanes[i].at(j).getYear() << " " << tollLanes[i].at(j).getMake();
                        cout << " (" <<  tollLanes[i].at(j).getTransponder() << ")]"<< endl;
                    }
                }
                
                if (tollLanes[i].empty())
                    cout << "   [Empty]" << endl;
            }
        }
            
        cout << "---------\n";    // count is increased
        count++;
    }
    
    cout << "SIMULATION COMPLETE" << endl;     // message notifying toll is complete
   
    return 0;
}

int rand_num() {    // Function to generate random number
    random_device randNum;
    uniform_int_distribution<int>range(0, 3);
    int num = range(randNum);

    return num;
}

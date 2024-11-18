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

int rand_num();

int main() {
    deque<Car> tollLanes[SIZE];    // array of deques initlized
    
    for (int i = 0; i < SIZE; i++) {    // each lane populated with 3 cars
        for (int j = 0; j < 3; j++) {
            Car newCar;
            tollLanes[i].push_back(newCar);
        }
    }
    
    cout << "Intial Queue:" << endl;    // inital queue of each lane is printed
    for (int i = 0; i < SIZE; i++) {
        cout << "Lane: " << i+1 << endl;
        for (auto j = 0; j < tollLanes[i].size(); j++) {
            cout << setw(WIDTH) << "[" << tollLanes[i].at(j).getYear() << " " << tollLanes[i].at(j).getMake();
            cout << " (" <<  tollLanes[i].at(j).getTransponder() << ")]"<< endl;
        }
    }
    cout << "------------------\n";
    
    static int count = 0;
    while (count < 20) {    // while loop to run 20 time intervals
        cout << "Time: " << count + 1 << endl;
        
        for (int i = 0; i < SIZE; i++) {
            int oper = rand() % 100 + 1;
            cout << "| Lane " << i+1 << " | ";
            
            
            if (!tollLanes[i].empty()) {    // All done if the lane is not empty
                if (oper <= c15) {   // chance car shifts lanes
                   
                    int shifLane = rand_num();    // random numer hcosen within range of lanes, car moves to that lane
                    tollLanes[shifLane].push_back(tollLanes[i].at(tollLanes[i].size() - 1));
                    
                    cout << "Shifted to lane " << shifLane + 1 << ": [" << tollLanes[i].at(tollLanes[i].size() - 1).getYear() << " ";
                    cout << tollLanes[i].at(tollLanes[i].size() - 1).getMake();
                    cout<< " (" <<  tollLanes[i].at(tollLanes[i].size() - 1).getTransponder() << ")]"<< endl;
                    
                    tollLanes[i].pop_back();
                }
                
                else if (oper < c15 + c39) { // chance car added to lane
                    Car newCar;
                    tollLanes[i].push_back(newCar);
                    cout << "Joined: [" << newCar.getYear() << " " << newCar.getMake();
                    cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
                }
                
                else if (oper > c39 && !tollLanes[i].empty()) {   // chance car leaves toll booth
                    cout << "Paid: [" << tollLanes[i].at(0).getYear() << " " << tollLanes[i].at(0).getMake();
                    cout<< " (" << tollLanes[i].at(0).getTransponder() << ")]"<< endl;
                    tollLanes[i].pop_front();
                }
            }
            
            else if (tollLanes[i].empty() && oper < 50) {    // done only if lane is empty, 50% chance a new Car enters
                Car newCar;
                tollLanes[i].push_back(newCar);
                cout << "Joined: [" << newCar.getYear() << " " << newCar.getMake();
                cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
            }
    
            else
                cout << "No change" << endl;    // message indicatig thee has been no change,
        }                                       // if no cars added to an empty lane or changed with an occupied lane
            
        cout << endl;
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
                    cout << "   [No Cars]" << endl;
            }
        
            
        cout << "------------------\n";    // count is increased
        count++;
    }
    
    cout << "SIMULATION COMPLETE" << endl;     // message notifying toll is complete
    return 0;
}

int rand_num() {    // Function to generate random number for a  shifted lane
    random_device randNum;
    uniform_int_distribution<int>range(0, 3);
    int num = range(randNum);

    return num;
}

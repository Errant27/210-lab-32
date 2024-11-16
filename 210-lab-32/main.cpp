#include <iostream>
#include <iomanip>
#include <deque>
#include <random>
#include "Car.h"
using namespace std;

const int SIZE = 2;
const int WIDTH = 3;
int rand_num();

int main() {
    deque<Car> tollBooth(SIZE);    // Deque initlized, size declaration auiomatically constructs 2 Cars in the deque
    
    cout << "Intial queue:" << endl;
    for (auto i = 0; i < tollBooth.size(); i++) {    // Outputs the inital queue
        cout << setw(WIDTH) << "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
        cout << " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
    }
    cout << "---------\n";
    
    static int count = 1;    // satic int to keep count of the number of times perations are done
    while (tollBooth.empty() == false) {
        cout << "Time: " << count << endl;
        int oper = rand_num();    // int variable gets a random number to determine operation
        
        if (oper <= 45) {   // 45% chance new car arrives at toll booth
            Car newCar;
            tollBooth.push_back(newCar);
            cout << "Operation: Car joined toll; [" << newCar.getYear() << " " << newCar.getMake();
            cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
        }
        else if (oper > 45) {   // 55% head car pays and leaves
            cout << "Operation: Car paid toll; [" << tollBooth.at(0).getYear() << " " << tollBooth.at(0).getMake();
            cout<< " (" <<  tollBooth.at(0).getTransponder() << ")]"<< endl;
            tollBooth.pop_front();
        }
    
        if (tollBooth.empty() == false) {    // if the cue has not been emptied after an operation has been complete, the updated list is printed
            cout << "Updated Queue:" << endl;
            for (auto i = 0; i < tollBooth.size(); i++) {    // Outputs the updated queue
                cout << setw(WIDTH) << "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
                cout << " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
            }
        }
        cout << "---------\n";    // count is increased
        count++;
    }
    cout << "TOLL BOOTH COMPLETE" << endl;     // message notifying toll is complete
   
    return 0;
}

int rand_num() {    // Function to generate random number
    random_device randNum;
    uniform_int_distribution<int>range(1, 100);
    int num = range(randNum);
    
    return num;
}

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
    deque<Car> tollBooth(SIZE);
    
    cout << "Intial queue:" << endl;
    for (auto i = 0; i < tollBooth.size(); i++) {    // Outputs the inital queue of the deque
        cout << setw(WIDTH) << "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
        cout << " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
    }
    cout << "---------\n";
    
    static int count = 1;
    while (tollBooth.empty() == false) {
        cout << "Time: " << count << endl;
        int oper = rand_num();
        
        
        if (oper <= 45) {
            Car newCar;
            tollBooth.push_back(newCar);
            cout << "Operation: Car joined toll; [" << newCar.getYear() << " " << newCar.getMake();
            cout<< " (" <<  newCar.getTransponder() << ")]"<< endl;
        }
        else if (oper > 45) {
            cout << "Operation: Car paid toll; [" << tollBooth.at(0).getYear() << " " << tollBooth.at(0).getMake();
            cout<< " (" <<  tollBooth.at(0).getTransponder() << ")]"<< endl;
            tollBooth.pop_front();
        }
    
        if (tollBooth.empty() == false) {
            cout << "Updated Queue:" << endl;
            for (auto i = 0; i < tollBooth.size(); i++) {
                cout << setw(WIDTH) << "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
                cout << " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
            }
        }
        cout << "---------\n";
        count++;
    }
    cout << "[TOLL BOOTH COMPLETE]" << endl;
   
    return 0;
}

int rand_num() {
    random_device randNum;
    uniform_int_distribution<int>range(1, 100);
    int num = range(randNum);
    
    return num;
}

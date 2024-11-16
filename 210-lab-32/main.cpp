#include <iostream>
#include <iomanip>
#include <deque>
#include <random>
#include "Car.h"
using namespace std;

const int SIZE = 2;

int main() {
    deque<Car> tollBooth(SIZE);
    
    cout << "Intial deque:" << endl;
    for (auto i = 0; i < tollBooth.size(); i++) {    // Outputs the inital queue
        cout<< "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
        cout<< " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
    }
    cout << "---------\n";
    
    Car car1;
    tollBooth.push_back(car1);
    Car car2;
    tollBooth.push_back(car2);
    Car car3;
    tollBooth.push_back(car3);
    Car car4;
    tollBooth.push_back(car4);
    
    cout << "Updated deque:" << endl;
    for (auto i = 0; i < tollBooth.size(); i++) {    // Outputs the inital queue
        cout<< "[" << tollBooth.at(i).getYear() << " " << tollBooth.at(i).getMake();
        cout<< " (" <<  tollBooth.at(i).getTransponder() << ")]"<< endl;
    }
    cout << "---------\n";
    return 0;
}

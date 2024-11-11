#include "Car.h"
#include <iostream>
#include <deque>
using namespace std;

const int SIZE = 2;
const int CYCLES = 6;

int main()
{
    deque<Car> line;

    cout << "Initial queue :" << endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        line.push_back(Car());
        cout << "[" << line.back().getYear() << " " << line.back().getMake() << " (" << line.back().getTransponder() << ")]" << endl;
    }
    cout << endl;
    
    for (size_t i = 0; i < CYCLES; i++)
    {
        cout << "Time: " << i+1 << " Operation: ";
        
    }
}
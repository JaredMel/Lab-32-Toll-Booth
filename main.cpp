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
        cout << "   [" << line.back().getYear() << " " << line.back().getMake() << " (" << line.back().getTransponder() << ")]" << endl;
    }
    cout << endl;
    
    for (size_t i = 0; i < CYCLES; i++)
    {
        int prob = rand() % 100 + 1;
        cout << "Time: " << i+1 << " Operation: ";

        if (prob <= 55)
        {
            line.push_back(Car());
            cout << "Joined lane: [" << line.back().getYear() << " " << line.back().getMake() << " (" << line.back().getTransponder() << ")]" << endl;
        }
        else if (prob <= 45)
        {
            cout << "Car paid: [" << line.front().getYear() << " " << line.front().getMake() << " (" << line.front().getTransponder() << ")]" << endl;
            line.pop_front();
        }

        cout << "Queue:" << endl;
        for (size_t i = 0; i < line.size(); i++)
        {
            cout << "   " << line[i].print() << endl;
        }
    }
}
#include "Car.h"
#include <iostream>
#include <deque>
using namespace std;

const int SIZE = 2;
const int CYCLES = 6;

int main()
{
    deque<Car> line;
    int count = 0;

    cout << "Initial queue :" << endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        line.push_back(Car());
        cout << "   ";
        line.back().print();
    }
    cout << endl;
    
    while(!line.empty())
    {
        count++;
        int prob = rand() % 100 + 1;
        cout << "Time: " << count << endl;

        if (prob <= 55)
        {
            line.push_back(Car());
            cout << "Operation: Joined lane: ";
            line.back().print();
            prob = rand() % 100 + 1;
        }
        else if (prob <= 45 && !line.empty())
        {
            cout << "Operation: Car paid: ";
            line.front().print();
            line.pop_front();
            prob = rand() % 100 + 1;
        }

        cout << "Queue:" << endl;
        if (!line.empty())
        {
            for (size_t i = 0; i < line.size(); i++)
            {
                cout << "   ";
                line[i].print();
            }
        }
        else
        {
            cout << "   Empty" << endl;
        }
    }
}
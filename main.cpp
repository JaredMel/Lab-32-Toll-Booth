#include "Car.h"
#include <iostream>
#include <deque>
#include <array>
using namespace std;

const int SIZE = 2;
const int CYCLES = 20;
const int NUM_LANES = 4;

int main()
{
    deque<Car> line;
    array<deque<Car>, NUM_LANES> lanes;
    int count = 0;
    int prob;

    cout << "Initial queue :" << endl;
    for (size_t i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i+1 << ":" << endl;
        for (size_t i = 0; i < SIZE; i++)
        {
            lanes[i].push_back(Car());
            cout << "   ";
            lanes[i].back().print();
        }
    }
    cout << endl;
    
    while(count < CYCLES)
    {
        count++;
        cout << "Time: " << count << endl;

        for (size_t i = 0; i < NUM_LANES; i++)
        {
            prob = rand() % 100 + 1;

            if (prob <= 45)
            {
                cout << "Lane: " << i+1 << " Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
                prob = rand() % 100 + 1;
            }
            if (prob <= 55)
            {
                lanes[i].push_back(Car());
                cout << "Lane: " << i+1 << "Joined: ";
                lanes[i].back().print();
                prob = rand() % 100 + 1;
            }
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
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
    int prob, ran;

    cout << "Initial queue :" << endl;
    for (size_t i = 0; i < NUM_LANES; i++)
    {
        cout << "Lane " << i+1 << ":" << endl;
        for (size_t j = 0; j < SIZE; j++)
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

            if (prob <= 46 && !lanes[i].empty())
            {
                cout << "Lane: " << i+1 << " Paid: ";
                lanes[i].front().print();
                lanes[i].pop_front();
                prob = rand() % 100 + 1;
            }
            if (prob <= 39)
            {
                lanes[i].push_back(Car());
                cout << "Lane: " << i+1 << " Joined: ";
                lanes[i].back().print();
                prob = rand() % 100 + 1;
            }
            else if (prob <= 50 && lanes[i].empty())
            {
                lanes[i].push_back(Car());
                cout << "Lane: " << i+1 << " Joined: ";
                lanes[i].back().print();
                prob = rand() % 100 + 1;
            }
            if (prob <= 15 && !lanes[i].empty())
            {
                do
                {
                    ran = rand() % NUM_LANES;
                } while (ran == i);

                lanes[ran].push_back(lanes[i].back());
                lanes[i].pop_back();
                cout << "Lane: " << i+1 << " Switched: ";
                lanes[ran].back().print();
                prob = rand() % 100 + 1;
            }
            
        }

        for (size_t i = 0; i < NUM_LANES; i++)
        {
            cout << "Lane " << i+1  << " Queue:" << endl;

            if (!lanes[i].empty())
            {
                for (size_t j = 0; j < lanes[i].size(); j++)
                {
                    cout << "   ";
                    lanes[i][j].print();
                }
            }
            else
            {
                cout << "   Empty" << endl;
            }
        }
        cout << endl;
    }
}
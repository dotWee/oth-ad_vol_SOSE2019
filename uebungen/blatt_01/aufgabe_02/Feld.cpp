#include <cstring>
#include <cstdlib>
#include <iostream>
#include <random>
#include <limits>
#include "Feld.h"

void Feld::Init(int length)
{
    this->length = length;

    array = (int *)malloc(sizeof(int) * length);

    // Fülle Array mit 0
    memset(array, 0, sizeof(int) * length);
};

void Feld::FillRandom()
{
    std::random_device rd;                          // obtain a random number from hardware
    std::mt19937 eng(rd());                         // seed the generator
    std::uniform_int_distribution<> distr(0, 1000); // define the range

    for (int n = 0; n < length; ++n)
    {
        array[n] = distr(eng);
    }
}

int Feld::Min()
{
    int lowest = INT_MAX;

    for (int position = 0; position < length; ++position)
    {
        if (array[position] < lowest)
        {
            lowest = array[position];
        }
    }

    return lowest;
}

int Feld::Max()
{
    int largest = INT_MIN;

    for (int position = 0; position < length; ++position)
    {
        if (array[position] > largest)
        {
            largest = array[position];
        }
    }

    return largest;
}

int Feld::Avg()
{
    int average = 0;

    for (int position = 0; position < length; ++position)
    {
        average += array[position];
    }

    average = average / length;

    return average;
}

void Feld::Print()
{
    for (int position = 0; position < length; ++position)
    {
        std::cout << "Position=" << position << " Value=" << array[position] << "\n";
    }
}